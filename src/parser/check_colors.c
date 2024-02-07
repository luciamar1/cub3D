#include "cub3d.h"


int choose_rgb(t_rgb *colors, char *nums)
{
    int num;
    int err_atoi;

    err_atoi = 0;
    num = ft_atoi_better(nums, &err_atoi);
    if(err_atoi)
        return(0);
    if(num >= 0 && num <= 255)
    {
        if(colors->r == -1)
            colors->r = num;
        else if(colors->g == -1)
            colors->g = num;
        else if(colors->b == -1)
            colors->b = num;
        return(1);
    }
    return(0);
}
t_rgb    check_rgb(char **nums, int *err, int *check)
{
    int counter;
    t_rgb color;

    counter = 0;
    while(*nums)
    {
        move_to_space(&(*nums));
        if(isdigit_str(*nums))
        {
            counter ++;
            if(counter > 3)
                return((*err = -1), color);
            if(!choose_rgb(&color, *nums))
                return((*err = -1), color);
            //move_to_space(&(*nums));
        }
        else
        {
            *err += 1;
            *check = 0;
            return (color);
        }
        nums ++;
    }

    *check = 1;
    return (color);
}
void    put_value_rgb(t_rgb *colors, int value)
{
    
        colors->r = value;
        colors->g = value;
        colors->b = value;
}
int    check_colors(char   *str, int *err, char cf, int *check, t_rgb *color)
{
    char    **nums;
    t_rgb color_aux;
    put_value_rgb(&color_aux, -1);
    //t_rgb   color;

    //color.g = ((color.r = -1), (color.b = -1), -1);
    nums = NULL;
    move_to_space(&str);
    if ((*str == cf && is_space(str[1])))
    {
        str ++;
        move_to_space(&str);
        nums = ft_split(str, ',');
        if(!nums)
            return(print_error("malloc error\n"), (*err = -1), 1);
        color_aux = check_rgb(nums, err, check);
        if(*err == -1)
            return(1);
        *color = color_aux;  
    }
    else 
        *err += 1;
    return (1);
}



int    try_colors(char   *str_doc, int *err_doc, t_colors *doc_rgb)
{
    int     check;

    check = 0;
    check_colors(str_doc, err_doc, 'C', &check, &doc_rgb->ceiling);
    printf("try == %d  %d  %d\n", doc_rgb->ceiling.b, doc_rgb->ceiling.r, doc_rgb->ceiling.g);
    if (check)
    {
        
        return(1);
    }
    check_colors(str_doc, err_doc, 'F', &check, &doc_rgb->floor);
    if (check)
    {
        return (1);
    }
    return (0);
}

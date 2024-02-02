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
        if(!colors->r)
            colors->r = num;
        else if(!colors->g)
            colors->g = num;
        else if(!colors->b)
            colors->b = num;
        return(1);
    }
    return(0);
}
int    check_rgb(char **nums, int *err, t_rgb *color, int *check)
{
    int counter;

    counter = 0;
    while(*nums)
    {
        move_to_space(&(*nums));
        if(isdigit_str(*nums))
        {
            counter ++;
            if(counter > 3)
                return((*err = -1), 0);
            if(!choose_rgb(color, *nums))
                return((*err = -1), 0);
        }
        else
        {
            *err += 1;
            *check = 0;
            return (0);
        }
        nums ++;
    }
    *check = 1;
    return (0);
}

t_rgb    check_colors(char   *str, int *err, char cf, int *check)
{
    char    **nums;
    char    **aux;
    t_rgb   color;

    color.g = (color.r = 0), (color.b = 0), 0;
    nums = NULL;
    aux = NULL;
    move_to_space(&str);
    if ((*str == cf && is_space(str[1])))
    {
        str ++;
        move_to_space(&str);
        nums = ft_split(str, ',');
        if(!nums)
            return((*err = -1), color);
        aux = nums;
        check_rgb(nums, err, &color, check);
        free_biarr(aux);
        if(*err == -1)
            return(color);
    }
    else 
        *err += 1;
    return (color);
}

int    try_colors(char   *str_doc, int *err_doc, t_colors *doc_rgb)
{
    int     check;
    t_rgb   rgb;

    check = 0;
    rgb = check_colors(str_doc, err_doc, 'C', &check);
    if (check)
    {
        doc_rgb->ceiling = rgb;
        return(1);
    }
    rgb = check_colors(str_doc, err_doc, 'F', &check);
    if (check)
    {
        doc_rgb->floor = rgb;
        return (1);
    }
    return (0);
}

#include "cub3d.h"

int check_volume_nums(char *str)
{
	int counter;

    counter = 0;
    while (counter++ < 2)
    {
        move_to_space(&str);
        if (ft_isdigit(*str)) {
            while (ft_isdigit(*str))
                str ++;
        }
		else
			return 0;
		move_to_space(&str);
        if (*str == ',')
            str ++;
		else
			return 0;
    }
    move_to_space(&str);
	if (ft_isdigit(*str))
		while (ft_isdigit(*str))
			str ++;
	else
		return 0;
	move_to_space(&str);
	return (*str == 0);
}

int put_rgb(char **nums, int *doc_rgb, int *color)
{
    int counter;
    int rgb[3];
    int atoi_err;

    counter = 0;
    atoi_err = 0;
    while(*nums)
    {
        move_to_space(nums);
        rgb[counter] = ft_atoi_better(*nums, &atoi_err);
        if(atoi_err)
            return(0);
        if(((rgb[counter] < 0 || rgb[counter] > 255)))
            return(0);
        counter ++;
        nums ++;
    }
    *doc_rgb = rgb[2];
    *doc_rgb += rgb[1] << 8;
    *doc_rgb += rgb[0] << 16;
    color[0] = 1;
    return(1);
}

void   check_rgb(char *str, int *err_doc, int *doc_rgb, int *colors)
{
    char **nums;

    move_to_space(&str);
    if (!is_digit_space_str(str) || !check_volume_nums(str))
    {
        *err_doc = -1;
        return ;
    }
    nums = ft_split(str, ',');
    if(!nums)
    {
        *err_doc = -1;
        return ;
    }
    if (!put_rgb(nums, doc_rgb, colors))
        *err_doc = -1;
}

int	try_colors(char *str_doc, int *err_doc, t_doc *doc, int *colors)
{
    if (!ft_strncmp(str_doc, "C ", 2) && !colors[0])
       return ((check_rgb(str_doc + 1, err_doc, &(doc->colors.ceiling), &colors[0])), 1);
    else
        *err_doc += 1;
    if (!ft_strncmp(str_doc, "F ", 2) && !colors[1])
       return ((check_rgb(str_doc + 1, err_doc, &(doc->colors.floor), &colors[1])), 1);
    else
        *err_doc += 1;
    return (0);
}

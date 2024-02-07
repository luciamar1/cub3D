#include "cub3d.h"

void    put_value_color(t_colors *colors, int value, char   type)
{
    if(type == 'c' || type == 't')
    {
        colors->ceiling.r = value;
        colors->ceiling.g = value;
        colors->ceiling.b = value;
    }

    if (type == 'f' || type == 't')
    {
        colors->floor.r = value;
        colors->floor.g = value;
        colors->floor.b = value;   

    }
}
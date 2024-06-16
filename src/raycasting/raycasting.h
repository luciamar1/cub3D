#ifndef RAYCASTING_H
# define RAYCASTING_H

#include "../cub3d.h"


typedef struct s_float_vector
{
	float	x;
	float	y;
}				t_float_vector;

typedef struct s_map
{
	t_float_vector	person;
	t_float_vector	direction;
    float           angle;      //in degrees, 0 is looking south
	char			**bimap;
}				t_map;

float	ray(t_map map, t_float_vector *colision, t_float_vector direction);
#endif
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
	float			distance;
	char			**bimap;
}				t_map;

float calculate_distance(t_map *map);
#endif
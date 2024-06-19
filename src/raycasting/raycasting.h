#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "../cub3d.h"

typedef struct s_float_vector
{
	float	x;
	float	y;
}	t_fvector;

typedef struct s_map
{
	t_fvector	person;
	t_fvector	direction;
	float		angle; // in degrees, 0 is looking south
	char		**bimap;
}	t_map;

t_fvector	next_check(t_fvector start, t_fvector direction);
int			is_wall(t_fvector collision, t_fvector direction, char **bimap);
float		ray(t_map map, t_fvector *colision, t_fvector direction);
int			raymove(t_map map, t_fvector direction, t_fvector final);

#endif

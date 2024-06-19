/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:47:20 by mde-arpe          #+#    #+#             */
/*   Updated: 2024/06/05 01:40:18 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
void		ray(t_map map, t_fvector *collision, t_fvector direction);
int			raymove(t_map map, t_fvector direction, t_fvector final);
float		v_distance(t_fvector v1, t_fvector v2);

#endif

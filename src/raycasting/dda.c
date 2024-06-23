/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:47:20 by mde-arpe          #+#    #+#             */
/*   Updated: 2024/06/23 19:35:59 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	v_distance(t_fvector v1, t_fvector v2)
{
	t_fvector	subs;
	float		prode;

	subs.x = v1.x - v2.x;
	subs.y = v1.y - v2.y;
	prode = powf(subs.x, 2) + powf(subs.y, 2);
	return (sqrt(prode));
}

void	ray(t_map map, t_fvector *collision, t_fvector direction)
{
	int	found;

	collision->x = map.person.x;
	collision->y = map.person.y;
	found = 0;
	while (!found)
	{
		*collision = next_check(*collision, direction);
		found = is_wall(*collision, direction, map.bimap);
	}
}

//return false if cant move
int	raymove(t_map map, t_fvector direction, t_fvector final)
{
	int			found;
	t_fvector	collision;

	collision.x = map.person.x;
	collision.y = map.person.y;
	found = 0;
	while (!found)
	{
		collision = next_check(collision, direction);
		if (v_distance(map.person, collision) > v_distance(map.person, final))
			break ;
		found = is_wall(collision, direction, map.bimap);
	}
	return (!found);
}

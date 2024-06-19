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

#include "cub3d.h"

int	close_win(t_doc *doc)
{
	if (doc->program.image)
		mlx_destroy_image(doc->program.mlx_ptr, doc->program.image);
	mlx_clear_window(doc->program.mlx_ptr, doc->program.window);
	mlx_destroy_window(doc->program.mlx_ptr, doc->program.window);
	free_biarr_int((void **) doc->textures.so, IMAGESIZE);
	free_biarr_int((void **) doc->textures.ea, IMAGESIZE);
	free_biarr_int((void **) doc->textures.no, IMAGESIZE);
	free_biarr_int((void **) doc->textures.we, IMAGESIZE);
	free_biarr((void **) doc->map.bimap);
	exit(0);
}

float	add_angle(float angle, float toAdd)
{
	angle += toAdd;
	while (angle < 0)
		angle += 360;
	while (angle >= 360)
		angle -= 360;
	return (angle);
}

t_fvector	angle_to_direction(float angle)
{
	t_fvector	v;

	v.x = cosf(angle * 2 * M_PI / 360);
	v.y = sinf(angle * 2 * M_PI / 360);
	return (v);
}

void	move(float x, float y, t_fvector *person, t_map map)
{
	t_fvector	moved_to;
	t_fvector	direction;

	moved_to.x = person->x + x * (float) MOVE;
	moved_to.y = person->y + y * (float) MOVE;
	direction.x = x;
	direction.y = y;
	if (raymove(map, direction, moved_to))
	{
		person->x = moved_to.x;
		person->y = moved_to.y;
	}
}

int	keypress(int keycode, t_doc *doc)
{
	if (keycode == W)
		move(doc->map.direction.x, doc->map.direction.y, \
			&(doc->map.person), doc->map);
	else if (keycode == A)
		move(-1 * doc->map.direction.y, doc->map.direction.x, \
			&(doc->map.person), doc->map);
	else if (keycode == S)
		move(-1 * doc->map.direction.x, -1 * doc->map.direction.y, \
			&(doc->map.person), doc->map);
	else if (keycode == D)
		move(doc->map.direction.y, -1 * doc->map.direction.x, \
			&(doc->map.person), doc->map);
	else if (keycode == RIGHT || keycode == LEFT)
	{
		if (keycode == RIGHT)
			doc->map.angle = add_angle(doc->map.angle, -ROTATE);
		if (keycode == LEFT)
			doc->map.angle = add_angle(doc->map.angle, ROTATE);
		doc->map.direction = angle_to_direction(doc->map.angle);
	}
	else if (keycode == ESC)
		close_win(doc);
	render(doc);
	return (0);
}

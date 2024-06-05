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

void	put_pixel(t_img *img, int color, int x, int y) {
	img->data[(x * WINDOW_SIZE + y) * 4] = color;
	img->data[(x * WINDOW_SIZE + y) * 4 + 1] = color >> 8;
	img->data[(x * WINDOW_SIZE + y) * 4 + 2] = color >> 16;
	img->data[(x * WINDOW_SIZE + y) * 4 + 3] = 0;
}

//returns a column of pixels of a given texture
int	*pixel_col(int** texture, float colision) {
	return texture[(int) (IMAGESIZE * colision)]; //pensar en el roundf aqui
}

float	add_angle(float angle, float toAdd) {
	angle += toAdd;
	while (angle < 0)
		angle += 360;
	while (angle >= 360)
		angle -= 360;
	return angle;
}

void	paint_col(t_img *image, t_float_vector colision, float distance, int** texture, int n, t_doc *doc) {
	int			*pixels;
	long double	size;

	if (colision.x == (int) colision.x)
		pixels = pixel_col(texture, colision.y - (int) colision.y);
	else
		pixels = pixel_col(texture, colision.x - (int) colision.x);
	size = WINDOW_SIZE / distance;
	if (distance < 0.00001)
		size = INT_MAX;
	for (int i = 0; i < WINDOW_SIZE; i++)
	{
		if (i < WINDOW_SIZE / 2 - size / 2)
			put_pixel(image, doc->colors.ceiling, i, n);
		else if (i > WINDOW_SIZE / 2 + size / 2)
			put_pixel(image, doc->colors.floor, i, n);
		else
			put_pixel(image, pixels[(int) ((i - WINDOW_SIZE / 2 + size / 2) * IMAGESIZE / size)], i, n);
	}
}

void	render(t_doc* doc) {
	t_float_vector	colision;
	float			distance;
	float			curr_angle;
	int				cnt;
	t_img*			image;

	cnt = 0;
	curr_angle = add_angle(doc->map.angle, -VISION / 2);
	image = mlx_new_image(doc->program.mlx_pointer, WINDOW_SIZE, WINDOW_SIZE);
	if (!image) {
		print_error("couldnt create image\n");
		return ;
	}
	while (cnt < RAYS)
	{
		distance = calc_distance_new(&(doc->map), &colision, angleToDirection(curr_angle));
		printf("map: cd.cub\n");
		printf("person: %f, %f\n", doc->map.person.x, doc->map.person.y);
		printf("direction: %f, %f\n", angleToDirection(curr_angle).x, angleToDirection(curr_angle).y);
		printf("colides in: %f, %f\n\n", colision.x, colision.y);
		paint_col(image, colision, distance, doc->textures.ea, cnt, doc);
		cnt++;
		curr_angle = add_angle(curr_angle, (float) VISION / (float) RAYS);
	}
	mlx_put_image_to_window(doc->program.mlx_pointer, doc->program.window, image, 0, 0);
}

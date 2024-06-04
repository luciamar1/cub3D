/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:47:20 by mde-arpe          #+#    #+#             */
/*   Updated: 2024/06/04 22:42:21 by mde-arpe         ###   ########.fr       */
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
	return texture[(int) roundf(IMAGESIZE * colision)];
}

float	add_angle(float angle, float toAdd) {
	angle += toAdd;
	while (angle < 0)
		angle += 360;
	while (angle >= 360)
		angle -= 360;
	return angle;
}

void printi(int* a) {
	for (int i = 0; i < IMAGESIZE; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void	paint_col(t_img *image, t_float_vector colision, float distance, int** texture, int n, t_doc *doc) {
	int			*pixels;
	long long	size;

	if (colision.x == (int) colision.x)
		pixels = pixel_col(texture, colision.y - (int) colision.y);
	else
		pixels = pixel_col(texture, colision.x - (int) colision.x);
	size = WINDOW_SIZE / distance;
	for (int i = 0; i < WINDOW_SIZE; i++)
	{
		if (i < WINDOW_SIZE / 2 - size / 2)
			put_pixel(image, doc->colors.ceiling, i, n);
		else if (i > WINDOW_SIZE / 2 + size / 2)
			put_pixel(image, doc->colors.floor, i, n);
		else
			put_pixel(image, pixels[(i - WINDOW_SIZE / 2 + size / 2) * IMAGESIZE / size], i, n);
	}
}

void	render(t_doc* doc) {
	t_float_vector	colision;
	float			distance;
	int				curr_angle;
	int				cnt;
	t_img*			image;

	cnt = 0;
	curr_angle = add_angle(doc->map.angle, -VISION / 2);
	image = mlx_new_image(doc->program.mlx_pointer, WINDOW_SIZE, WINDOW_SIZE);
	// if (!image)
	// 	return ; //print error, crash or return if failed to generate image
	// while (cnt < RAYS)
	// {
		//get colision for ray
		distance = 1;
		colision.x = 10;
		colision.y = 0;

		for (int i = 0; i < 64; i++) {
			colision.y += 1.0/64.0;
			paint_col(image, colision, distance, doc->textures.ea, cnt, doc);
			cnt++;
		}
		
		
		curr_angle = add_angle(curr_angle, (float) VISION / (float) RAYS);
	// }
	mlx_put_image_to_window(doc->program.mlx_pointer, doc->program.window, image, 0, 0);
}

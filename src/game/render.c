/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:47:20 by mde-arpe          #+#    #+#             */
/*   Updated: 2024/06/04 21:52:47 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void put_pixel(t_img *img, int color, int x, int y) {
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

void paint_col(t_img *image, t_float_vector colision, float distance, int** texture, int n) {
	int	*pixels;

	(void) distance;
	if (colision.x == (int) colision.x)
		pixels = pixel_col(texture, colision.y - (int) colision.y);
	else
		pixels = pixel_col(texture, colision.x - (int) colision.x);
	for (int i = 0; i < 64; i++)
		put_pixel(image, pixels[i], i + 500, n);
}

void render(t_doc* doc) {
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
		distance = 0;
		colision.x = 10;
		colision.y = 10.2;
		
		
		paint_col(image, colision, distance, doc->textures.ea, cnt);
		curr_angle = add_angle(curr_angle, (float) VISION / (float) RAYS);
		cnt++;
	// }
	mlx_put_image_to_window(doc->program.mlx_pointer, doc->program.window, image, 0, 0);
}

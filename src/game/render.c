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
	img->data[(x * WINDOW_WIDTH + y) * 4] = color;
	img->data[(x * WINDOW_WIDTH + y) * 4 + 1] = color >> 8;
	img->data[(x * WINDOW_WIDTH + y) * 4 + 2] = color >> 16;
	img->data[(x * WINDOW_WIDTH + y) * 4 + 3] = 0;
}

//returns a column of pixels of a given texture
int	*pixel_col(int** texture, float collision) {
	return texture[(int) roundf((IMAGESIZE - 1) * collision)];
}

float	add_angle(float angle, float toAdd) {
	angle += toAdd;
	while (angle < 0)
		angle += 360;
	while (angle >= 360)
		angle -= 360;
	return angle;
}

void	paint_col(t_img *image, t_float_vector collision, float distance, int** texture, int n, t_doc *doc) {
	int			*pixels;
	long double	size;

	if (collision.x == (int) collision.x)
		pixels = pixel_col(texture, collision.y - (int) collision.y);
	else
		pixels = pixel_col(texture, collision.x - (int) collision.x);
	size = WINDOW_HEIGHT / (2 * distance);
	if (distance < 0.00001)
		size = INT_MAX;
	for (int i = 0; i < WINDOW_HEIGHT; i++)
	{
		if (i < WINDOW_HEIGHT / 2 - size / 2)
			put_pixel(image, doc->colors.ceiling, i, n);
		else if (i > WINDOW_HEIGHT / 2 + size / 2)
			put_pixel(image, doc->colors.floor, i, n);
		else
			put_pixel(image, pixels[(int) roundf((IMAGESIZE - 1) * (i - WINDOW_HEIGHT / 2 + size / 2) / size)], i, n);
	}
}

int	**choose_texture(t_textures t, float angle, t_float_vector collision)
{
	if (collision.y == (float) (int) collision.y)
	{
		if (angle >= 0 && angle <= 180)
			return t.we;
		else
			return t.ea;
	}
	else
	{
		if (angle >= 90 && angle <= 270)
			return t.so;
		else
			return t.no;
	}
}

void	render(t_doc* doc) {
	t_float_vector	collision;
	float			distance;
	float			curr_angle;
	int				cnt;
	t_img*			image;

	cnt = 0;
	curr_angle = add_angle(doc->map.angle, VISION / 2);
	image = mlx_new_image(doc->program.mlx_pointer, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!image) {
		print_error("couldnt create image\n");
		return ;
	}
	while (cnt < WINDOW_WIDTH)
	{
		distance = ray(doc->map, &collision, angleToDirection(curr_angle));
		paint_col(image, collision, distance, choose_texture(doc->textures, curr_angle, collision), cnt, doc);
		cnt++;
		curr_angle = add_angle(curr_angle, (float) -VISION / (float) WINDOW_WIDTH);
	}
	mlx_put_image_to_window(doc->program.mlx_pointer, doc->program.window, image, 0, 0);
	if (doc->program.image)
		mlx_destroy_image(doc->program.mlx_pointer, doc->program.image);
	doc->program.image = image;
}

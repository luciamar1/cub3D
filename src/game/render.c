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

void	put_pixel(t_img *img, int color, int x, int y)
{
	img->data[(x * WIN_W + y) * 4] = color;
	img->data[(x * WIN_W + y) * 4 + 1] = color >> 8;
	img->data[(x * WIN_W + y) * 4 + 2] = color >> 16;
	img->data[(x * WIN_W + y) * 4 + 3] = 0;
}

//returns a column of pixels of a given texture
int	*pixel_col(int **texture, t_fvector collision)
{
	float	i;

	if (collision.x == (int) collision.x)
		i = collision.y - (int) collision.y;
	else
		i = collision.x - (int) collision.x;
	return (texture[(int) roundf((IMAGESIZE - 1) * i)]);
}

void	paint_col(float distance, int *pixels, int n, t_doc *doc)
{
	long double	sz;
	int			i;
	int			pos;

	sz = WIN_H / (2 * distance);
	if (distance < 0.00001)
		sz = INT_MAX;
	i = 0;
	while (i < WIN_H)
	{
		if (i < WIN_H / 2 - sz / 2)
			put_pixel(doc->program.next_image, doc->colors.ceiling, i, n);
		else if (i > WIN_H / 2 + sz / 2)
			put_pixel(doc->program.next_image, doc->colors.floor, i, n);
		else
		{
			pos = roundf((IMAGESIZE - 1) * (i - WIN_H / 2 + sz / 2) / sz);
			put_pixel(doc->program.next_image, pixels[pos], i, n);
		}
		i++;
	}
}

int	**choose_texture(t_textures t, float angle, t_fvector collision)
{
	if (collision.y == (float)(int) collision.y)
	{
		if (angle >= 0 && angle <= 180)
			return (t.we);
		else
			return (t.ea);
	}
	else
	{
		if (angle >= 90 && angle <= 270)
			return (t.so);
		else
			return (t.no);
	}
}

void	render(t_doc *doc)
{
	t_fvector		collision;
	float			curr_angle;
	int				cnt;
	int				*pixels;

	doc->program.next_image = mlx_new_image(doc->program.mlx_ptr, WIN_W, WIN_H);
	if (!doc->program.next_image)
		return (print_error("couldnt create image\n"), (void) 42);
	cnt = 0;
	curr_angle = add_angle(doc->map.angle, VISION / 2);
	while (cnt < WIN_W)
	{
		ray(doc->map, &collision, angle_to_direction(curr_angle));
		pixels = pixel_col(choose_texture(doc->textures, \
						curr_angle, collision), collision);
		paint_col(v_distance(collision, doc->map.person), pixels, cnt, doc);
		cnt++;
		curr_angle = add_angle(curr_angle, (float) -VISION / (float) WIN_W);
	}
	mlx_put_image_to_window(doc->program.mlx_ptr, doc->program.window, \
							doc->program.next_image, 0, 0);
	if (doc->program.image)
		mlx_destroy_image(doc->program.mlx_ptr, doc->program.image);
	doc->program.image = doc->program.next_image;
}

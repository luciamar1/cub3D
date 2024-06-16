#include "cub3d.h"

int	close_win(t_doc *doc)
{
	if (doc->program.image)
		mlx_destroy_image(doc->program.mlx_pointer, doc->program.image);
	mlx_clear_window(doc->program.mlx_pointer, doc->program.window);
	mlx_destroy_window(doc->program.mlx_pointer, doc->program.window);
	free_biarr_int((void **) doc->textures.so, IMAGESIZE);
	free_biarr_int((void **) doc->textures.ea, IMAGESIZE);
	free_biarr_int((void **) doc->textures.no, IMAGESIZE);
	free_biarr_int((void **) doc->textures.we, IMAGESIZE);
	free_biarr((void **) doc->map.bimap);
	//free_write_exit(NULL, mlx->map, NULL, 0);
	exit(0);
}

t_float_vector	angleToDirection(float angle)
{
	t_float_vector v;

	v.x = cosf(angle * 2 * M_PI / 360);
	v.y = sinf(angle * 2 * M_PI / 360);
	return (v);
}

void	move(float x, float y, t_float_vector* person, char** map) 
{
	(void) map;
	person->x += x * MOVE;
	person->y += y * MOVE;

	printf("position: %f, %f\n", person->x, person->y);
}

int keypress(int keycode, t_doc *doc)
{
	if (keycode == W)
		move(doc->map.direction.x, doc->map.direction.y, &(doc->map.person), doc->map.bimap);
	else if (keycode == A)
		move(-1 * doc->map.direction.y, doc->map.direction.x, &(doc->map.person), doc->map.bimap);
	else if (keycode == S)
		move(-1 * doc->map.direction.x, -1 * doc->map.direction.y, &(doc->map.person), doc->map.bimap);
	else if (keycode == D)
		move(doc->map.direction.y, -1 * doc->map.direction.x, &(doc->map.person), doc->map.bimap);
	else if (keycode == RIGHT || keycode == LEFT) {
		if (keycode == RIGHT)
			doc->map.angle = add_angle(doc->map.angle, -ROTATE);
		if (keycode == LEFT)
			doc->map.angle = add_angle(doc->map.angle, ROTATE);
		doc->map.direction = angleToDirection(doc->map.angle);
		printf("angle: %f, dir: %f, %f\n", doc->map.angle, doc->map.direction.x, doc->map.direction.y);
	}
	else if (keycode == ESC)
		close_win(doc);
	render(doc);
	return (0);
}

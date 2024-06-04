#include "cub3d.h"

int	close_win(t_doc *doc)
{
	mlx_clear_window(doc->program.mlx_pointer, doc->program.window);
	mlx_destroy_window(doc->program.mlx_pointer, doc->program.window);
	//free_write_exit(NULL, mlx->map, NULL, 0);
	exit(0);
}

void	angleToDirection(float angle, t_float_vector *v)
{
	v->x = cosf(angle * 2 * M_PI / 360);
	v->y = sinf(angle * 2 * M_PI / 360);
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
		move(doc->map.direction.y, -1 * doc->map.direction.x, &(doc->map.person), doc->map.bimap);
	else if (keycode == S)
		move(-1 * doc->map.direction.x, -1 * doc->map.direction.y, &(doc->map.person), doc->map.bimap);
	else if (keycode == D)
		move(-1 * doc->map.direction.y, doc->map.direction.x, &(doc->map.person), doc->map.bimap);
	else if (keycode == RIGHT || keycode == LEFT) {
		if (keycode == RIGHT)
			doc->map.angle = add_angle(doc->map.angle, -1 * ROTATE);
		if (keycode == LEFT)
			doc->map.angle = add_angle(doc->map.angle, ROTATE);
		angleToDirection(doc->map.angle, &(doc->map.direction));
		printf("angle: %f, dir: %f, %f\n", doc->map.angle, doc->map.direction.x, doc->map.direction.y);
	}
	else if (keycode == ESC)
		close_win(doc);
	render(doc);
	return (0);
}

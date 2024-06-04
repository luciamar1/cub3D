#include "cub3d.h"

int	close_win(t_doc *doc)
{
    mlx_clear_window(doc->program.mlx_pointer, doc->program.window);
    mlx_destroy_window(doc->program.mlx_pointer, doc->program.window);
    //free_write_exit(NULL, mlx->map, NULL, 0);
    exit(0);
}

void    angleToDirection(float angle, t_float_vector *v) {
	v->x = cosf(angle * 2 * M_PI / 360);
    v->y = sinf(angle * 2 * M_PI / 360);
}

void   move(float x, float y, t_float_vector* person, char** map) {

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
        if (keycode == RIGHT) {
            doc->map.angle -= ROTATE;
            while (doc->map.angle < 0)
                doc->map.angle += 360;
        }
        if (keycode == LEFT) {
            doc->map.angle += ROTATE;
            while (doc->map.angle >= 360)
                doc->map.angle -= 360;
        }
        angleToDirection(doc->map.angle, &(doc->map.direction));
        printf("angle: %f, dir: %f, %f\n", doc->map.angle, doc->map.direction.x, doc->map.direction.y);
    }
	else if (keycode == ESC)
		close_win(doc);
    return (0);
}

int main(int argc, char **argv)
{
	int		err;
	t_doc	doc;

	err = 0;
	doc = parser(argc, argv, &err);
	if (err)
		return (1);
	printf("mapa bueno\n\n");
	printf("\n\nmain\nperson %f %f\n", doc.map.person.x, doc.map.person.y);
    printf("orientation %f %f\n", doc.map.direction.x, doc.map.direction.y);

    doc.program.window = mlx_new_window(doc.program.mlx_pointer, 600, 600, "cub3d");
    mlx_hook(doc.program.window, 17, 0b100, close_win, &doc);
    mlx_hook(doc.program.window, 2, 0b1, keypress, &doc);
    mlx_loop(doc.program.mlx_pointer);
	return (0);
}

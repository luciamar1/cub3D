#include "cub3d.h"

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

	doc.program.window = mlx_new_window(doc.program.mlx_pointer, WINDOW_SIZE, WINDOW_SIZE, "cub3d");
	mlx_hook(doc.program.window, 17, 0b100, close_win, &doc);
	mlx_hook(doc.program.window, 2, 0b1, keypress, &doc);
	mlx_loop(doc.program.mlx_pointer);
	return (0);
}

#include "cub3d.h"

int main(int argc, char **argv)
{
	int		err;
	t_doc	doc;
	
	err = 0;
	doc = parser(argc, argv, &err);
	if (err)
		return (1);
	doc.program.image = NULL;
	doc.program.window = mlx_new_window(doc.program.mlx_pointer, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	mlx_hook(doc.program.window, 17, 0b100, close_win, &doc);
	mlx_hook(doc.program.window, 2, 0b1, keypress, &doc);
	render(&doc);
	mlx_loop(doc.program.mlx_pointer);
	return (0);
}

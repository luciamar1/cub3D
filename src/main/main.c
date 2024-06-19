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

int	main(int argc, char **argv)
{
	int		err;
	t_doc	doc;

	err = 0;
	doc = parser(argc, argv, &err);
	if (err)
		return (1);
	doc.program.image = NULL;
	doc.program.window = mlx_new_window(doc.program.mlx_ptr, \
										WIN_W, WIN_H, "cub3d");
	mlx_hook(doc.program.window, 17, 0b100, close_win, &doc);
	mlx_hook(doc.program.window, 2, 0b1, keypress, &doc);
	render(&doc);
	mlx_loop(doc.program.mlx_ptr);
	return (0);
}

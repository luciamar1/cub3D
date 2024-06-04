/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:40:56 by mde-arpe          #+#    #+#             */
/*   Updated: 2024/06/04 16:40:58 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
#define GAME_H

#include "../parser/parser.h"

# define MOVE       0.1 //cuadrados por pulsacion
# define ROTATE     5   //grados por pulsacion
# define RAYS       100 //numero de rayos
# define VISION     120 //grados de vision

# define ESC		65307
# define W		    119
# define A		    97
# define S		    115
# define D		    100

# define UP		    65362
# define LEFT		65361
# define DOWN		65364
# define RIGHT		65363

int		keypress(int keycode, t_doc *doc);
int		close_win(t_doc *doc);
void	render(t_doc *doc);

#endif
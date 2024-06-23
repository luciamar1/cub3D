/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:40:56 by mde-arpe          #+#    #+#             */
/*   Updated: 2024/06/23 19:38:42 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "../parser/parser.h"

# define MOVE 0.25	// cuadrados por pulsacion
# define ROTATE 5   // grados por pulsacion
# define VISION 110 // grados de vision

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100

# define LEFT 65361
# define RIGHT 65363

int			keypress(int keycode, t_doc *doc);
t_fvector	angle_to_direction(float angle);
int			close_win(t_doc *doc);
float		add_angle(float angle, float toAdd);
void		render(t_doc *doc);

#endif
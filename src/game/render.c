/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:47:20 by mde-arpe          #+#    #+#             */
/*   Updated: 2024/06/04 19:01:43 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//returns a column of pixels of a given texture
char*	pixel_col(char** texture, float colision) {
	return texture[(int) roundf(IMAGESIZE * colision)];
}



void render(t_doc* doc) {
	int				**data;
	// t_float_vector	colision;
	// float			distance;

	data = doc->textures.ea;
	for (int i = 0; i < 64; i++) {
		for (int j = 0; j< 64; j++)
			printf("%i ", data[j][i]);
		printf("\n");
	}
}

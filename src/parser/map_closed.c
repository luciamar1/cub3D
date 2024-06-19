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

int	is_orientation(char orientation)
{
	if (orientation == 'N' || orientation == 'S' \
		|| orientation == 'E' || orientation == 'W')
		return (1);
	return (0);
}

int	recursive_function(char **map, size_t x, size_t y)
{
	if (!map[x] || ft_strlen(map[x]) <= y)
		return (0);
	if (map[x][y] == 'C')
		return (1);
	if (map[x][y] == '1')
	{
		map[x][y] = 'C';
		return (1);
	}
	if (map[x][y] == '0')
	{
		map[x][y] = 'C';
		return (recursive_function(map, x - 1, y) \
				&& recursive_function(map, x, y - 1) \
				&& recursive_function(map, x + 1, y) \
				&& recursive_function(map, x, y + 1));
	}
	return (0);
}

int	verify_if_close(char **str)
{
	int	x;
	int	y;
	int	br;

	x = 0;
	y = 0;
	br = 0;
	while (str[x])
	{
		while (str[x][y])
		{
			if (is_orientation(str[x][y]))
				br = 1;
			if (br)
				break ;
			y++;
		}
		if (br)
			break ;
		y = 0;
		x ++;
	}
	str[x][y] = '0';
	return (recursive_function(str, x, y));
}

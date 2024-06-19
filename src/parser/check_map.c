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

t_fvector	put_orientation(int x, int y)
{
	t_fvector	orientation;

	orientation.x = x;
	orientation.y = y;
	return (orientation);
}

void	put_person_direction(t_map *map, char orientation, int prim, int seg)
{
	if (orientation == 'N')
	{
		map->direction = put_orientation(-1, 0);
		map->angle = 180;
	}
	else if (orientation == 'S')
	{
		map->direction = put_orientation(1, 0);
		map->angle = 0;
	}
	else if (orientation == 'E')
	{
		map->direction = put_orientation(0, 1);
		map->angle = 90;
	}
	else if (orientation == 'W')
	{
		map->direction = put_orientation(0, -1);
		map->angle = 270;
	}
	map->person.x = prim + 0.5;
	map->person.y = seg + 0.5;
}

void	place_person(char **map, t_map *map_params)
{
	int	prim;
	int	seg;

	prim = 0;
	while (map[prim])
	{
		seg = 0;
		while (map[prim][seg])
		{
			if (is_orientation(map[prim][seg]))
				put_person_direction(map_params, map[prim][seg], prim, seg);
			seg++;
		}
		prim++;
	}
}

int	verif_characters(char **map)
{
	int	person;
	int	prim;
	int	seg;

	prim = 0;
	person = 0;
	while (map[prim])
	{
		seg = 0;
		while (map[prim][seg])
		{
			if (map[prim][seg] == 0x20)
				map[prim][seg] = '0';
			else if (is_orientation(map[prim][seg]))
				person++;
			else if (!(map[prim][seg] == '1' || map[prim][seg] == '0'))
				return (0);
			seg ++;
		}
		prim++;
	}
	return (person == 1);
}

int	check_map(t_doc *doc)
{
	char	**aux;
	char	**real_map;

	if (!verif_characters(doc->map.bimap))
		return (print_error("invalid characters\n"), 0);
	aux = strdup_bi(doc->map.bimap);
	if (!aux)
		return (print_error("malloc fail\n"), 0);
	if (!verify_if_close(aux))
		return (print_error("map not closed\n"), free_biarr((void **) aux), 0);
	real_map = create_real_map(aux, doc->map.bimap);
	free_biarr((void **) aux);
	free_biarr((void **) doc->map.bimap);
	if (!real_map)
		return (print_error("malloc fail\n"), 0);
	doc->map.bimap = real_map;
	place_person(doc->map.bimap, &(doc->map));
	return (1);
}

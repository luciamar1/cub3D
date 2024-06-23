/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_create_doc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:47:20 by mde-arpe          #+#    #+#             */
/*   Updated: 2024/06/23 18:56:08 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_map(char **str_doc, int *err, t_doc *doc)
{
	str_doc++;
	doc->map.bimap = strdup_bi(str_doc);
	if (!doc->map.bimap)
	{
		print_error("malloc error\n");
		*err = 1;
	}
	return ;
}

t_doc	check_create_document(char **str_doc, int *err)
{
	t_doc	doc;
	int		err_doc;
	int		colors;
	int		text;
	int		creat[6];

	colors = (ft_bzero(&doc, sizeof(t_doc)), ft_bzero(creat, 24), 0);
	doc.program.mlx_ptr = ((text = 0), mlx_init());
	if (!doc.program.mlx_ptr)
		return (print_error("mlx_init fail\n"), (*err = 1), doc);
	while (*str_doc)
	{
		colors += ((err_doc = 0), try_colors(*str_doc, &err_doc, &doc, creat));
		if (err_doc == -1)
			return (print_error("error in colors\n"), (*err = 1), doc);
		text += try_textures(*str_doc, &err_doc, &doc, creat);
		if (err_doc == -1)
			return (print_error("error in textures\n"), (*err = 1), doc);
		if (err_doc == 6)
			return (print_error("invalid content in doc\n"), (*err = 1), doc);
		if (colors == 2 && text == 4)
			return ((create_map(str_doc, err, &doc)), doc);
		str_doc++;
	}
	return (*err = 1, print_error("incomplete doc\n"), doc);
}

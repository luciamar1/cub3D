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

int	check_extension(char *document)
{
	if (ft_str_rev_n_cmp(document, ".cub", 4))
		return (0);
	return (1);
}

t_doc	parser(int argc, char **argv, int *err_parser)
{
	char	**strbi_doc;
	t_doc	doc;
	int		err;

	err = 0;
	ft_bzero(&doc, sizeof(t_doc));
	if (argc != 2)
	{
		print_error("incorrect number of arguments\n");
		return ((*err_parser = 1), doc);
	}
	if (!check_extension(argv[1]))
		return ((print_error("incorrect extension\n")), (*err_parser = 1), doc);
	strbi_doc = read_document(argv[1]);
	if (!strbi_doc)
		return ((print_error("doc cant be read\n")), (*err_parser = 1), doc);
	doc = check_create_document(strbi_doc, &err);
	free_biarr((void **) strbi_doc);
	if (err)
		return ((*err_parser = 1), doc);
	if (!check_map(&doc))
		return ((print_error("map error\n")), (*err_parser = 1), doc);
	return ((*err_parser = 0), doc);
}

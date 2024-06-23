/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_doc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:47:20 by mde-arpe          #+#    #+#             */
/*   Updated: 2024/06/23 18:52:10 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_doc(t_doc doc)
{
	if (doc.program.mlx_ptr)
	{
		mlx_destroy_display(doc.program.mlx_ptr);
		free(doc.program.mlx_ptr);
	}
	free_biarr_int((void **) doc.textures.so, IMAGESIZE);
	free_biarr_int((void **) doc.textures.ea, IMAGESIZE);
	free_biarr_int((void **) doc.textures.no, IMAGESIZE);
	free_biarr_int((void **) doc.textures.we, IMAGESIZE);
	free_biarr((void **) doc.map.bimap);
}

char	**read_document(char *extension)
{
	char	*line_document;
	char	*new_line;
	int		fd;
	char	**doc;
	char	*aux[2];

	fd = ((line_document = NULL), open(extension, O_RDONLY));
	if (fd < 0)
		return (printf("the file can't be open\n"), NULL);
	while (1)
	{
		new_line = get_next_line(fd);
		if (!new_line)
			break ;
		aux[1] = ((aux[0] = line_document), new_line);
		line_document = ft_strjoin_better(&line_document, &new_line);
		free(aux[0]);
		free(aux[1]);
		if (!line_document)
			return (free(new_line), NULL);
	}
	doc = ft_split(line_document, '\n');
	if (line_document)
		free(line_document);
	return (doc);
}

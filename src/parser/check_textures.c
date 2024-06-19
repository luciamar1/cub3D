/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:59:42 by mde-arpe          #+#    #+#             */
/*   Updated: 2024/06/04 20:02:33 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	**create_texture(char *data)
{
	int	**ret;
	int	c1;
	int	c2;

	ret = (int **) alloc_biarr(IMAGESIZE, IMAGESIZE * 4);
	if (!ret)
		return (NULL);
	c1 = 0;
	while (c1 < IMAGESIZE)
	{
		c2 = 0;
		while (c2 < IMAGESIZE)
		{
			ret[c2][c1] = data[(c1 * IMAGESIZE + c2) * 4] << 0;
			ret[c2][c1] += data[(c1 * IMAGESIZE + c2) * 4 + 1] << 8;
			ret[c2][c1] += data[(c1 * IMAGESIZE + c2) * 4 + 2] << 16;
			c2++;
		}
		c1++;
	}
	return (ret);
}

//return the textures as a matrix BY COLUMNS
//(convenient, bc we will paint by columns)
int	**check_textures(char *str_doc, int *err_doc, t_doc *doc, int *textures)
{
	void	*img;
	char	*data;
	int		hei;
	int		wid;
	int		**ret;

	str_doc += 2;
	move_to_space(&str_doc);
	img = mlx_xpm_file_to_image(doc->program.mlx_ptr, str_doc, &wid, &hei);
	if (!img || wid != IMAGESIZE || hei != IMAGESIZE)
		return ((*err_doc = -1), NULL);
	data = mlx_get_data_addr(img, &wid, &wid, &wid);
	if (!data)
	{
		mlx_destroy_image(doc->program.mlx_ptr, img);
		return ((*err_doc = -1), NULL);
	}
	ret = create_texture(data);
	mlx_destroy_image(doc->program.mlx_ptr, img);
	if (!ret)
		return ((*err_doc = -1), NULL);
	*textures = 1;
	return (ret);
}

int	clasificate_textures(char *str_doc, int *err_doc, t_doc *doc, int *textures)
{
	if (!ft_strncmp(str_doc, "NO ", 3) && !textures[2])
		return (doc->textures.no = check_textures(str_doc, \
									err_doc, doc, &textures[2]), 1);
	else
		*err_doc += 1;
	if (!ft_strncmp(str_doc, "SO ", 3) && !textures[3])
		return (doc->textures.so = check_textures(str_doc, \
									err_doc, doc, &textures[3]), 1);
	else
		*err_doc += 1;
	if (!ft_strncmp(str_doc, "WE ", 3) && !textures[4])
		return (doc->textures.we = check_textures(str_doc, \
									err_doc, doc, &textures[4]), 1);
	else
		*err_doc += 1;
	if (!ft_strncmp(str_doc, "EA ", 3) && !textures[5])
		return (doc->textures.ea = check_textures(str_doc, \
									err_doc, doc, &textures[5]), 1);
	else
		*err_doc += 1;
	return (0);
}

int	try_textures(char *str_doc, int *err_doc, t_doc *doc, int *textures)
{
	int	ret;

	move_to_space(&str_doc);
	ret = clasificate_textures(str_doc, err_doc, doc, textures);
	return (ret);
}

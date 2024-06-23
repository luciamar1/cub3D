/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:47:20 by mde-arpe          #+#    #+#             */
/*   Updated: 2024/06/23 18:44:02 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../cub3d.h"
# include "libft.h"
# include "raycasting/raycasting.h"

# define IMAGESIZE 64

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_minilib
{
	void	*mlx_ptr;
	void	*window;
	void	*image;
	void	*next_image;
}	t_minilib;

typedef struct s_textures
{
	int	**no;
	int	**so;
	int	**we;
	int	**ea;
}	t_textures;

typedef struct s_colors
{
	int	ceiling;
	int	floor;
}	t_colors;

typedef struct s_doc
{
	t_colors	colors;
	t_textures	textures;
	t_minilib	program;
	t_map		map;
}	t_doc;

// parser
t_doc	parser(int argc, char **argv, int *err);
t_doc	check_create_document(char **str_doc, int *err);
int		try_colors(char *str_doc, int *err_doc, t_doc *doc, int *colors);
int		check_map(t_doc *doc);
int		is_space(char character);
int		move_to_space(char **str);
char	**read_document(char *extension);
int		try_textures(char *str_doc, int *err_doc, t_doc *doc, int *textures);
char	**create_real_map(char **check, char **map);
int		ft_str_rev_n_cmp(const char *s1, const char *s2, size_t n);
int		verify_if_close(char **str);
int		is_orientation(char orientation);
void	free_doc(t_doc doc);

#endif
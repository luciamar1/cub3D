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

#ifndef UTILS_H
# define UTILS_H

# include "libft.h"
# include "parser/parser.h"
# include "../cub3d.h"

//utils
void	free_biarr(void **fr);
void	free_biarr_int(void **fr, int size);
char	*ft_strjoin_better(char **s1, char **s2);
char	**strdup_bi(char **str);
void	print_error(char *message);
int		ft_atoi_better(const char *str, int *error);
int		is_digit_space_str(char *str);
void	**alloc_biarr(int dim1, int dim2);
char	**level1_copy(char **tocpy);

#endif

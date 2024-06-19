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

char	*ft_strjoin_better(char **s1, char **s2)
{
	char	*s;
	int		l;
	int		counter;

	counter = 0;
	if (!*s2)
		return (NULL);
	if (*s1)
		l = ft_strlen(*s1) + ft_strlen(*s2);
	else
		l = ft_strlen(*s2);
	s = malloc(l * sizeof(char) + 1);
	if (s == NULL)
		return (NULL);
	while (*s1 && s1[0][counter])
		*s++ = s1[0][counter++];
	counter = 0;
	while (s2[0][counter])
		*s++ = s2[0][counter++];
	*s = '\0';
	return (s - l);
}

int	strlen_bi(char **str)
{
	int	counter;

	counter = 0;
	while (*str)
	{
		str++;
		counter++;
	}
	return (counter);
}

char	**strdup_bi(char **str)
{
	char	**ret;
	int		len_bi;
	int		counter;

	counter = 0;
	len_bi = strlen_bi(str);
	ret = malloc(sizeof(char *) * (len_bi + 1));
	if (!ret)
		return (NULL);
	while (len_bi)
	{
		ret[counter] = ft_strdup(str[counter]);
		if (!ret[counter])
			return (free_biarr((void **) ret), NULL);
		counter ++;
		len_bi --;
	}
	ret[counter] = NULL;
	return (ret);
}

int	is_digit_space_str(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter] && (is_space(str[counter]) \
			|| ft_isdigit(str[counter]) || str[counter] == ','))
		counter++;
	if (str[counter])
		return (0);
	return (1);
}

void	print_error(char *message)
{
	while (*message)
		write(2, message++, 1);
}

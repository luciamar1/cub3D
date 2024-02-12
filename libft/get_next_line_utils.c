/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 21:10:09 by mde-arpe          #+#    #+#             */
/*   Updated: 2024/01/15 16:07:09 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*str_calloc(size_t count, size_t size)
{
	char			*ret;
	unsigned long	c;

	c = 0;
	ret = malloc(count * size);
	if (ret == NULL)
		return (NULL);
	while (c < count)
		ret[c++] = 0;
	return (ret);
}

//realoca
char	*my_realloc(char *str, int *realloc_counter)
{
	char	*ret;
	int		counter;

	ret = str_calloc(BUFFER_SIZE * ++(*realloc_counter) + 1, 1);
	if (!ret)
		return (NULL);
	counter = 0;
	while (str[counter])
	{
		ret[counter] = str[counter];
		counter++;
	}
	free(str);
	return (ret);
}

void	free_and_null(t_read *red)
{
	free(red->already_read);
	red->already_read = NULL;
}

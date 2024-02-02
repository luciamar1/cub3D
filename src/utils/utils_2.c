#include "cub3d.h"

void    print_error(char *message)
{
    while(*message)
        write(2, message++, 1);
}


int	ft_atoi_better(const char *str, int *error)
{
	int				c;
	unsigned int	x;

	c = 1;
	x = 0;
	while (*str)
	{
		while ((*str >= 9 && *str <= 13) || *str == ' ')
			str++;
		if (ft_isalpha(*str))
			return (*error = 1, 0);
		if (*str == '+' || *str == '-' || ft_isalpha(*str))
			if (*str++ == '-')
				c *= -1;
		while (*str <= '9' && *str >= '0')
			x = x * 10 + (*str++ - '0');
		if (x > 0x7fffffff && c == 1)
			return (*error = 1, 0);
		if (x > 0x80000000 && c == -1)
			return (*error = 1, 0);
		return (c * x);
		str++;
	}
	*error = 1;
	return (0);
}

void	free_biarr(char **fr)
{
	int	counter;

	if (fr)
	{
		counter = 0;
		while (fr[counter])
		{
			free(fr[counter]);
			counter++;
		}
		free(fr);
	}
}

void print_biarr(char **str)
{
	while(*str)
	{
		if(**str)
			printf("str == %s\n", *str);
		str++;
	}
}
int	ft_str_rev_n_cmp(const char *s1, const char *s2, size_t n)
{
	int	len;

	len = ft_strlen(s1) - n;
	if (n == 0)
		return (0);
	while (len --)
		s1++;
	while (*s1 && *s2 && *s1 == *s2 && --n)
	{
		s1 ++;
		s2 ++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}


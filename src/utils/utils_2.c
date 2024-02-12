#include "cub3d.h"

void    print_error(char *message)
{
    while(*message)
        write(2, message++, 1);
}

int	ft_atoi_better(const char *str, int *error)
{
	int				minus;
	long int		ret;
	int				counter;

	ret = 0;
	minus = 0;
	counter = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		if (*(str++) == '-')
			minus++;
	while (*str <= '9' && *str >= '0')
	{
		ret = ret * 10 + (*str++ - '0');
		counter++;
	}
	if (counter > 10 || (ret > 0x7fffffff && !minus)
		|| (ret > 0x80000000 && minus))
		return (*error = 1, 0);
	if (minus)
		ret *= -1;
	return (*error = 0, ret);
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

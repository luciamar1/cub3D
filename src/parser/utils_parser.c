#include "cub3d.h"

void    put_value_color(t_colors *colors, int value, char   type)
{
    if(type == 'c' || type == 't')
    {
        colors->ceiling.r = value;
        colors->ceiling.g = value;
        colors->ceiling.b = value;
    }

    if (type == 'f' || type == 't')
    {
        colors->floor.r = value;
        colors->floor.g = value;
        colors->floor.b = value;   

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


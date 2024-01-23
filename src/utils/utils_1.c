#include "../../cub3d.h"

int	ft_atoi_chetao(const char *str, int *error)
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

char	*ft_strjoin_chetao(char **s1, char **s2)
{
	char	*s;
	int		l;
	int		counter;

	counter = 0;
	if (!s2)
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
	*s = 0;
	if(*s2)
	 	free(*s2);
	if (*s1)
	  	free(*s1);
	return (s - l);
}

void	print_doc(t_doc doc)
{
	printf("\n\nDOC:\n\n");
	printf("   color ceiling == %d, %d , %d\n", doc.colors.ceiling.r, doc.colors.ceiling.g, doc.colors.ceiling.b);
	printf("   color floor == %d, %d , %d\n\n", doc.colors.floor.r, doc.colors.floor.g, doc.colors.floor.b);
	printf("   textures no == %d\n", doc.textures.no);
	printf("   textures so == %d\n", doc.textures.so);
	printf("   textures we == %d\n", doc.textures.we);
	printf("   textures ea == %d\n", doc.textures.ea);
}

int	isdigit_str(char *str)
{
	while(*str && ft_isdigit(*str))
		str ++;
	if(*str && !ft_isdigit(*str))
		return(0);
	return(1);
}

#include "../../cub3d.h"

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
	if(**s2)
	 	free(*s2);
	// if (**s1)
	//  	free(*s1);
	return (s - l);
}

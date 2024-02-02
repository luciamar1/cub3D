#include "cub3d.h"

char	*ft_strjoin_better(char **s1, char **s2)
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
	*s = '\0';
	return (s - l);
}

void	print_doc(t_doc doc)
{
	printf("\n\nDOC:\n\n");
	printf("   color ceiling == %d, %d , %d\n", doc.colors.ceiling.r, doc.colors.ceiling.g, doc.colors.ceiling.b);
	printf("   color floor == %d, %d , %d\n\n", doc.colors.floor.r, doc.colors.floor.g, doc.colors.floor.b);
	printf("\n\nMAP\n");
	print_biarr(doc.map);
}

int	isdigit_str(char *str)
{
    while(*str) 
	{
		if (!ft_isdigit(*str))
            return(0);
        str++;
    }
    return(1);

}

int	strlen_bi(char **str)
{
	int	counter;

	counter = 0;
	while(*str)
	{
		str++;
		counter ++;
	}
	return(counter);
};

char **strdup_bi(char **str)
{
	char	**ret;
	int		len_bi;
	int		counter;

	counter = 0;
	len_bi = strlen_bi(str);
	ret = malloc(sizeof(char *) *  (len_bi + 1));
	if (!ret)
		return(NULL);
	while(len_bi)
	{
		ret[counter] = ft_strdup(str[counter]);
		if(!ret[counter])
			return(free_biarr(ret), NULL);
		counter ++;
		len_bi --;
	}
	ret[counter] = NULL;
	return(ret);
}
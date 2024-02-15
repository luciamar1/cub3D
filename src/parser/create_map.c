#include "cub3d.h"

int len_first_realmap(char **check, int *pos_x_init)
{
    int init;
    int end;
    int x;
    int y;
    int len;

    init = ((len = 0), (end = -1), (x = 0), (y = 0), -1);
    while(check[x])
    {
        len ++;
        while(check[x][y])
        {
            if (check[x][y] == 'C')
            {
                if (init == -1)
                    *pos_x_init = ((init = len), x);
                end = len;
            }
            y ++;
        }
        y = ((x ++), 0);
    }
    return (end - init + 1);
}

int len_sec_realmap(char *check, int y)
{
    int len;
    int verif;

    len = 0;
    verif = 0;
    while(check[y])
    {
        if (check[y] == 'C')
        {
            verif = 1;
        }
        if(verif && check[y] != 'C')
            break ;
        len ++;
        y ++;
    }
    return(len);
}
char	*strdup_init_end(const char *s1, int len, int init)
{
	char	*ret;
	char	*ret_cpy;

	ret = ft_calloc(len + 1, 1);
	if (ret == NULL)
		return (ret);
	ret_cpy = ret;
	while (len)
    {
		*(ret++) = s1[init];
        init ++;
        len --;
    }
	return (ret_cpy);
}

int search_y_init(char **str)
{
    int x;
    int y;
    int position;

    x = 0;
    y = 0;
    while (str[x])
    {
        while (str[x][y])
        {
            if (str[x][y] == 'C')
            {
                if(y < position)
                    position = y;
                break;
            }
            y ++;
        }
        y = 0;
        x ++;
    }
    return(position);
}

char **create_real_map(char **check, char **map)
{
    char    **real;
    int     len_first;
    int     len_sec;
    int     x_init;
    int     y_init;
    int     x_real;

    x_real = ((x_init = 0), (y_init = search_y_init(check)), 0);
    len_first = len_first_realmap(check, &x_init);
    real = malloc(sizeof(char *) * (len_first + 1));
    if (!real)
        return(NULL);
    while (len_first)
    {
        len_sec = len_sec_realmap(check[x_init], y_init);
        real[x_real] =  strdup_init_end(map[x_init], len_sec, y_init);
        if (!real[x_real])
            return(free_biarr(real), NULL);
        x_init ++;
        x_real ++;
        len_first --;
    }
    real[x_real] = NULL;
    return(real);
}

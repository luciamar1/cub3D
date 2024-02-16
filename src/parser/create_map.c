#include "cub3d.h"

int len_first_realmap(char **check, int *pos_x_init)
{
    int init;
    int end;
    int x;
    int y;
    int len;

    init = ((len = 0), (end = -1), (x = 0), -1);
    while(check[x])
    {
        len ++;
        y = 0;
        while(check[x][y])
        {
            if (check[x][y] == 'C')
            {
                if (init == -1)
                    *pos_x_init = ((init = len), x);
                end = len;
				break ;
            }
            y ++;
        }
		x ++;
    }
    return (end - init + 1);
}

int len_sec_realmap(char *check, int y)
{
    int last;
	int y_copy;

	y_copy = y;
    while (check[y])
	{
        if (check[y] == 'C')
            last = y;
		y++;
	}
    return (last - y_copy + 1);
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
	position = -1;
    while (str[x])
    {
        while (str[x][y])
        {
            if (str[x][y] == 'C')
            {
                if (y < position || position == -1)
                    position = y;
                break ;
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
    int     x_init;
    int     y_init;
    int     x_real;

    len_first = len_first_realmap(check, &x_init);
    real = malloc(sizeof(char *) * (len_first + 1));
    if (!real)
        return (NULL);
	y_init = search_y_init(check);
    x_real = 0;
    while (len_first)
    {
		real[x_real] = strdup_init_end(map[x_init], \
			len_sec_realmap(check[x_init], y_init), y_init);
		if (!real[x_real])
            return(free_biarr(real), NULL);
        x_init ++;
        x_real ++;
        len_first --;
    }
    real[x_real] = NULL;
    return(real);
}

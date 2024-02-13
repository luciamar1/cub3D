#include "cub3d.h"

int verify_line(char *str)
{
    int ret;

    ret = 0;
    while(*str)
    {
        if(*str == '1')
            ret = 1;
        str ++;
    }
    return(ret);
}

int verify_colum(char **str, int y)
{
    int counter;
    int ret;

    ret = 0;
    counter = 0;
    print_biarr(str);
    while (str[counter])
    {
        printf("y == %c\n", str[counter][y]);
        if(ft_strlen(str[counter]) >= (size_t)y && str[counter][y] == '1')
            ret = 1;
        counter ++;
    }
    printf("\n\n");
    return (ret);
}

int verify_if_close(char **map)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (map[x])
    {
        
        if (!verify_line(map[x]))
            return (0);
        x ++;
    }
    while (map[0][y])
    {
        printf("map x == %s\n", map[0]);
        if (!verify_colum(map, y))
            return (0);
        y ++;
    }
    return (1);
}

int is_orientation(char orientation)
{
    if (orientation == 'N' || orientation == 'S' \
        || orientation == 'E' || orientation == 'W')
        return (1);
    return (0);
}

int verif_characters(char **map)
{
    int person;
    int prim;
    int seg;

    prim = 0;
    seg = 0;
    person = 0;
    while(map[prim])
    {
        while(map[prim][seg])
        {
            if(map[prim][seg] == '1' || map[prim][seg] == '0' \
            || is_space(map[prim][seg]) || is_orientation(map[prim][seg]))
            {
                if (is_space(map[prim][seg]))
                    map[prim][seg] = '0';
                if (is_orientation(map[prim][seg]))
                    person ++;
            }
            else 
                return(0);
            seg ++;
        }
        seg = 0;
        prim ++;
    }
    if (person != 1)
        return(0);
    return(1);
}

int check_map(char **map)
{
    char **aux;

    aux = map;
    if(!verif_characters(map))
        return (0);
    if(!verify_if_close(map))
        return (0);
    printf("person == \n");
    printf("YUPIJEIIII\n");
    return(1);
}

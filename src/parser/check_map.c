#include "cub3d.h"



int is_orientation(char orientation)
{
    if (orientation == 'N' || orientation == 'S' \
        || orientation == 'E' || orientation == 'W')
        return (1);
    return (0);
}
int recursive_function(char **map, size_t x, size_t y)
{
    if (x < 0 || !map[x] || ft_strlen(map[x]) <= y || y < 0)
        return (0);
    if (map[x][y] == 'C')
        return 1;
    if (map[x][y] == '1')
    {
        map[x][y] = 'C';
        return (1);
    }
    if (map[x][y] == '0') {
        map[x][y] = 'C';
        return (recursive_function(map, x - 1, y) && recursive_function(map, x, y - 1)\
                && recursive_function(map, x + 1, y) && recursive_function(map, x, y + 1));
    }
    return (0);
}

int verify_if_close(char **str)
{
    int x;
    int y;
    int br;

    x = 0;
    y = 0;
    br = 0;
    while(str[x])
    {
        while (str[x][y])
        {
            if (is_orientation(str[x][y]))
                br = 1;
            if (br)
                break;
            y ++;                
        }   
        if (br)
            break;
        y = 0;
        x ++;
    }
    str[x][y] = '0';
    return (recursive_function(str, x, y));
}




int verif_characters(char **map)
{
    int person;
    int prim;
    int seg;

    seg = ((prim = 0), (person = 0), 0);
    while(map[prim])
    {
        while(map[prim][seg])
        {
            if(map[prim][seg] == '1' || map[prim][seg] == '0' \
            || map[prim][seg] == 0x20  || is_orientation(map[prim][seg]))
            {
                if (map[prim][seg] == 0x20)
                    map[prim][seg] = '0';
                if (is_orientation(map[prim][seg]))
                    person ++;
            }
            else 
                return(0);
            seg ++;
        }
        seg = ((prim ++), 0);
    }
    if (person != 1)
        return(0);
    return(1);
}



int check_map(char **map, t_doc *doc)
{
    char **aux;
    char **real_map;

    if(!verif_characters(map))
        return (0);
    aux = strdup_bi(map);
    if (!aux)
        return(print_error("fail malloc\n"), 0);
    if(!verify_if_close(aux))
        return (0);
    real_map = create_real_map(aux, map);
    free_biarr(aux);
    free_biarr(doc->map);
    if(!real_map)
        return(print_error("fail malloc\n"),0);
    doc->map = real_map;
    return(1);
}

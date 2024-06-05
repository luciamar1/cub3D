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
    if (!map[x] || ft_strlen(map[x]) <= y )
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

t_float_vector  put_orientation(int x, int y)
{
    t_float_vector orientation;

    orientation.x = x;
    orientation.y = y;
    return (orientation);
}

void    put_person_direction(t_map *map, char orientation, int prim, int seg)
{
    if (orientation == 'N') {
        map->direction = put_orientation(-1, 0);
        map->angle = 180;
    }
    else if (orientation == 'S') {
        map->direction = put_orientation(1, 0);
        map->angle = 0;
    }
    else if (orientation == 'E') {
        map->direction = put_orientation(0, 1);
        map->angle = 90;
    }
    else if (orientation == 'W') {
        map->direction = put_orientation(0, -1);
        map->angle = 270;
    }

    map->person.x = prim + 0.5;
    map->person.y = seg + 0.5;
}


int verif_characters(char **map, t_map *map_params)
{
    int person;
    int prim;
    int seg;

	prim = 0;
    person = 0;
    while(map[prim])
    {
        seg = 0;
        while(map[prim][seg])
        {
            if(map[prim][seg] == '1' || map[prim][seg] == '0' \
            || map[prim][seg] == 0x20  || is_orientation(map[prim][seg]))
            {
                if (map[prim][seg] == 0x20)
                    map[prim][seg] = '0';
                if (is_orientation(map[prim][seg]))
                {
                    put_person_direction(map_params, map[prim][seg], prim, seg);
                    person ++;
                }
            }
            else 
                return (0);
            seg ++;
        }
		prim++;
    }
    return (person == 1);
}

int check_map(t_doc *doc)
{
    char **aux;
    char **real_map;

    if(!verif_characters(doc->map.bimap, &(doc->map)))
        return (print_error("invalid characters\n"), 0);
    aux = strdup_bi(doc->map.bimap);
    if (!aux)
        return (print_error("malloc fail\n"), 0);
    if(!verify_if_close(aux))
        return (print_error("map not closed\n"), free_biarr(aux), 0);
    real_map = create_real_map(aux, doc->map.bimap);
    free_biarr(aux);
    free_biarr(doc->map.bimap);
    if(!real_map)
        return (print_error("malloc fail\n"), 0);
    doc->map.bimap = real_map;

    
    return (1);
}

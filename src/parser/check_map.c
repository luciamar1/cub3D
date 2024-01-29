#include "../../cub3d.h"


int verif_characters(char **map)
{
    int prim;
    int seg;
    int person;

    prim = 0;
    seg = 0;
    person = 0;
    while(map[prim])
    {
        while(map[prim][seg])
        {
            if(map[prim][seg] == '1' || map[prim][seg] == '0' \
            || map[prim][seg] == ' ' || map[prim][seg] == 'N' \
            || map[prim][seg] == 'S' || map[prim][seg] == 'E' \
            || map[prim][seg] == 'W')
            {
                if (map[prim][seg] == ' ')
                    map[prim][seg] = '0';
                if (map[prim][seg] == 'N' || map[prim][seg] == 'S' \
                    || map[prim][seg] == 'E'|| map[prim][seg] == 'W')
                    person ++;
                seg ++;
            }
            else 
                return(0);
            if (person > 1)
                return(0);
        }
        seg = 0;
        prim ++;
    }
    return(1);
}

int check_map(char **map)
{
    if(!verif_characters(map))
        return (0);
    return(1);
}
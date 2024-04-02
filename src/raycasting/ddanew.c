#include "cub3d.h"
#include <math.h>
# include <unistd.h>
# include <stdio.h>

void    print_vector_new(t_vector vector, char *name)
{
    printf("\n%s\n", name);
    printf("vector  %d %d\n", vector.x, vector.y);
}

void    print_fvector_new(t_float_vector vector, char *name)
{
    printf("\n%s\n", name);
    printf("vector  %f %f\n", vector.x, vector.y);
}

t_vector    calc_walls(t_float_vector person, t_float_vector direction)
{
    t_vector    walls;
    if (direction.x < 0)
        walls.x = (int)person.x - 1;
    if (direction.y < 0)
        walls.y = (int)person.y - 1;
    
    if (direction.x > 0)
        walls.x = (int)person.x + 1;
    if (direction.y > 0)
        walls.y = (int)person.y + 1;
    
    if (direction.x == 0)
        walls.x = (int)person.x;
    if (direction.y == 0)
        walls.y = (int)person.y;
    return (walls);
}

float calc_distance_new(t_map *map)
{
    //float   distance;
    t_vector    walls;
    t_float_vector  ray;

    ray = map->person;
    while(1)
    {
        walls = calc_walls(ray, map->direction);
        print_vector_new(walls, "walls");
    }
}
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
        walls.x = (int)person.x;
    if (direction.y < 0)
        walls.y = (int)person.y;
    
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

t_float_vector  calc_wall_hit(t_float_vector  direction, t_vector walls)
{
    t_float_vector  wall_hit;

    if(direction.x >= 0)
        wall_hit.x = (float)walls.x;        
    if(direction.x < 0)
        wall_hit.x = (float)walls.x + 1;

    if(direction.y >= 0)
        wall_hit.y = (float)walls.y;        
    if(direction.y < 0)
        wall_hit.y = (float)walls.y + 1;
    return (wall_hit);
}
t_float_vector  vector_ray(int  x_y, t_float_vector p_ray, t_float_vector  direction, t_vector wall)
{
    t_float_vector vector_distance;
    t_float_vector walls;
    walls.x = wall.x;
    walls.y = wall.y;
    // wall_hit = calc_wall_hit(direction, walls);

    if (walls.x == p_ray.x && walls.y == p_ray.y)
    {
        printf("entras\n");
        sleep(1);
        vector_distance.x = 0;
        vector_distance.y = 0;
        return (vector_distance);
    }
    if (x_y == 0)
    {
        vector_distance.x = fabs(walls.x - p_ray.x);
        vector_distance.y = (vector_distance.x * direction.y) /direction.x;
    }
    if (x_y == 1)
    {
        vector_distance.y = fabs(walls.y - p_ray.y);
        vector_distance.x = (vector_distance.y * direction.x) / direction.y;
    }
    return(vector_distance);
}


int verif_walls(t_vector walls, t_float_vector p_ray,  t_float_vector  v_ray)
{
    t_vector    i_ray;

    i_ray.x = (int) (p_ray.x + v_ray.x);
    i_ray.y = (int) (p_ray.y + v_ray.y);
    print_vector_new(i_ray, "I_RAY");
    if (i_ray.x == walls.x && i_ray.y == walls.y)
        return (1);
    return (0);
}
t_vector    what_hit_wall(t_float_vector direction, t_float_vector p_ray)
{
    t_vector    hit_wall;

    if(direction.x < 0)
        hit_wall.x = p_ray.x - 1;
    if(direction.y < 0)
        hit_wall.y = p_ray.y - 1;

    if(direction.x >= 0)
        hit_wall.x = p_ray.x;
    if(direction.y >= 0)
        hit_wall.y = p_ray.y;
    return (hit_wall);
}

int verif_if_1(t_float_vector   p_ray, char **map, t_float_vector   direction)
{
    t_vector    hit_wall;
    printf("                         what_hit_wall\n");
    sleep(1);
    print_fvector_new(p_ray, "p_ray");
    hit_wall = what_hit_wall(direction, p_ray);
    print_vector_new(hit_wall, "hit wall");
    if(map[hit_wall.x][hit_wall.y] == '1')
        return(1);
    return (0);
}

float   calc_hypotenuse(t_float_vector p_ray, t_float_vector person)
{
    float   cathetus_a;
    float   cathetus_b;
    float   hypothenuse;

    cathetus_a = p_ray.x - person.x;
    cathetus_b = p_ray.y - person.y;
    hypothenuse = sqrt(cathetus_a * cathetus_a + cathetus_b * cathetus_b); 
    return (hypothenuse);
}

float   calc_distance(t_float_vector p_ray, t_float_vector person, t_float_vector direction, t_vector walls)
{
    t_float_vector wall_hit;

    wall_hit = calc_wall_hit(direction, walls);
    if((direction).x == 0 || (direction).y == 0)
    {
        return(fabs((p_ray.x - person.x) + (p_ray.y - person.y)));
    }
    return(calc_hypotenuse(p_ray, person));
}

float   check_distance(t_vector walls, t_float_vector *p_ray, t_map map)
{
    float           distance;
    t_float_vector  v_ray;
    int     x_y;

    distance = -42;
    x_y = 0;
    while(x_y <= 1)
    {
        v_ray = vector_ray(x_y, *p_ray, map.direction, walls);
        print_fvector_new(v_ray, "v_ray");
        print_fvector_new(*p_ray, "p_ray");
        sleep(1);
        if(verif_walls(walls, *p_ray, v_ray))
        {
            printf("             VERIF WALLS\n");
            sleep(1);
            (*p_ray).x += v_ray.x;
            (*p_ray).y += v_ray.y;
            if(verif_if_1(*p_ray, map.bimap, map.direction))
            {
                distance = calc_distance(*p_ray, map.person, map.direction, walls);
                return(distance);
            }
            else
                break;
        }
        x_y ++;
    }
    return(distance);
}

float calc_distance_new(t_map *map)
{
    float   distance;
    t_vector    walls;
    t_float_vector  p_ray;
    p_ray = map->person;
    while(1)
    {
        walls = calc_walls(p_ray, map->direction);
        print_vector_new(walls, "WALLS FIRST");
        print_fvector_new(p_ray, "P_RAY FIRST");
        distance = check_distance(walls, &p_ray, *map);
        if (distance >= 0)
            break ;
    }
    return(distance);
}
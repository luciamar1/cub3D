#include "cub3d.h"
#include <math.h>
# include <unistd.h>
# include <stdio.h>

void    print_vector(t_vector vector, char *name)
{
    printf("\n%s\n", name);
    printf("vector  %d %d\n", vector.x, vector.y);
}

void    print_fvector(t_float_vector vector, char *name)
{
    printf("\n%s\n", name);
    printf("vector  %f %f\n", vector.x, vector.y);
}

float choose_wall(float person, float direction)
{   
    if ((float) (int) person == person)
    {
        if (direction < 0)
            return (person - 1);
        if (direction > 0)
            return (person + 1);
        if (direction == 0)
            return(person);

        // if (direction < 0)
        //     return (person - 1);
        // if (direction > 0)
        //     return (person + 1);
        // if (direction == 0)
        //     return(person);
    }
    else
    {
        if (direction <= 0)
            return (floor(person));
        if (direction > 0)
            return (ceil(person));
    }
    return (-42);
}

t_float_vector choose_walls(t_float_vector person, t_float_vector direction)
{
    t_float_vector    wall;

    wall.x = choose_wall(person.x, direction.x);
    wall.y = choose_wall(person.y, direction.y);
    print_fvector(wall, "walls\n");
    sleep(2);
    return (wall);
}

float   calc_distance(float person, float   wall)
{
        return (wall - person);
}

t_float_vector calcular_hit(t_float_vector person, t_float_vector   wall, t_float_vector direction)
{
    t_float_vector hit;

    hit.x = wall.x;
    hit.y = wall.y;
    if((float) (int) person.y == person.y)
    {
        if (direction.y > 0)
            hit.y = wall.y - 1;
    
        if (direction.y < 0)
            hit.y = wall.y + 1;
    }
    if((float) (int) person.x == person.x)
    {
        
        if (direction.x > 0)
            hit.x = wall.x - 1;
    
        if (direction.x < 0)
            hit.x = wall.x + 1;
    }
    return(hit);
}

t_float_vector   vector_distance(t_float_vector person, t_float_vector   wall, t_float_vector direction, int x_y)
{
    t_float_vector vector_distance;
    if (x_y == 0)
    {
        vector_distance.x = calc_distance(person.x, wall.x);
        vector_distance.y = (vector_distance.x * direction.y) /direction.x;
    }
    if (x_y == 1)
    {
        vector_distance.y = calc_distance(person.y, wall.y);
        vector_distance.x = (vector_distance.y * direction.x) / direction.y;
    }
    print_fvector(vector_distance, "vector distance");
    return (vector_distance);
}
t_vector    what_verif(t_float_vector ray, t_float_vector   direction)
{
    t_vector    verif;

    verif.x = (int)floor(ray.x);
    verif.y = (int)floor(ray.y);
    if((float) (int) ray.x == ray.x)
    {
        if(direction.x < 0)
            verif.x = verif.x - 1;

    }
    if((float) (int) ray.y == ray.y)
    {
        if(direction.y < 0)
            verif.y = verif.y - 1;
    }
    return (verif);
}

int verif_mendi2(float person, float direction)
{
    if(direction >= 0)
    {
        return((int)person);
    }
    if(direction < 0)
    {
        if(person == 0)
            return((int)person);
        return((int)(person - 1));
    }
    else 
        return(-42);
}   

t_vector  verif_mendi(t_float_vector person, t_float_vector direction)
{
    t_vector    mendi;

    mendi.x = -42;
    mendi.y = -42;
    
    if ((float) (int) person.x == person.x)
    {
        mendi.x = verif_mendi2(person.x, direction.x);
    }
    if ((float) (int) person.y == person.y)
    {
        mendi.y = verif_mendi2(person.y, direction.y);
    }
    if(mendi.x == -42)
        mendi.x = floor(person.x);
    if(mendi.y == -42)    
        mendi.y = floor(person.y);
    // if(direction.x == 0)
    //     mendi.x = (int)floor(person.x);
    // if(direction.y == 0)
    //     mendi.y = (int)floor(person.y);
    // if((float) (int) person.x == person.x  && (float) (int) person.y == person.y && person.x != 0 && person.y != 0)
    // {
    //     if(direction.x < 0)
    //         mendi.x = person.x - 1;
    //     if(direction.y < 0)
    //         mendi.y = person.y - 1;
    //     if(direction.x > 0)
    //         mendi.x = (int)floor(person.x);
    //     if(direction.y > 0)
    //         mendi.y = person.y + 1;
    // }
    // else
    // {
    //     if(direction.x < 0)
    //         mendi.x = (int)floor(person.x);
    //     if(direction.y < 0)
    //         mendi.y = (int)floor(person.y);
    //     if(direction.x >  0)
    //         mendi.x = (int)ceil(person.x);
    //     if(direction.y >  0)
    //         mendi.y = (int)ceil(person.y);

    // }
    return(mendi);
}

t_vector verif_gg(t_float_vector person, t_float_vector direction)
{
    t_vector    mendi;
  

    if(direction.x <= 0)
        mendi.x = (int)floor(person.x);
    if(direction.y <= 0)
        mendi.y = (int)floor(person.y);

    if(direction.x >  0)
        mendi.x = (int)ceil(person.x);
    if(direction.y >  0)
        mendi.y = (int)ceil(person.y);
    return(mendi);
}

int verif_if_walls(t_float_vector person, t_float_vector distance, t_float_vector wall)
{
    t_vector    verif;
    person.x += distance.x;
    person.y += distance.y;


    verif = verif_gg(person, distance);
    print_vector(verif, "verif");
    if (verif.x == wall.x && verif.y == wall.y)
    {
        return(1);

    }
    
    return (0);
}


float   calc_hypotenuse(t_float_vector ray, t_float_vector origin, t_float_vector wall, t_float_vector direction)
{
    float   cathetus_a;
    float   cathetus_b;
    t_float_vector hit;
    float   hypothenuse;

    hit = calcular_hit(ray, wall, direction);
    print_fvector(hit, "hit");
    cathetus_a = calc_distance(hit.x, origin.x);
    cathetus_b = calc_distance(hit.y, origin.y);
    hypothenuse = sqrt(cathetus_a * cathetus_a + cathetus_b * cathetus_b); 
    return (hypothenuse);
}


float check_walls(t_float_vector *distance, t_float_vector *ray, t_float_vector *wall, t_map *map)
{
    t_vector        verif;
    int x_y;
    x_y = 1;

    while (x_y >= 0)
    {
            *distance = vector_distance(*ray, *wall, map->direction, x_y);
            if(verif_if_walls(*ray, *distance, *wall))
            {
                (*ray).x = (*ray).x + (*distance).x;
                (*ray).y = (*ray).y + (*distance).y;
                print_fvector(*ray, "ray\n");
                verif = verif_mendi((*ray), (map->direction));
                print_vector(verif, "verif\n");
                if (map->bimap[verif.x][verif.y] == '1')
                {
                    printf("verif if walls\n");
                    if((map->direction).x == 0 || (map->direction).y == 0)
                    {
                        t_float_vector hit;
                         hit = calcular_hit(*ray, *wall, *distance);
                        printf("guatafac 0\n");
                        print_fvector(hit, "hit");
                        print_fvector(*wall, "wall");
                        printf("hit.x - ray.x == %f\n hit.y - ray.y == %f\n", hit.x - (*ray).x, (*ray).y);
                        return(fabs(hit.x - (*ray).x) + hit.y - (*ray).y);
                    }
                    return (calc_hypotenuse((*ray), (map->person), *wall, *distance));
                }
                return(-69);
            }
            x_y  --;
        }
        return(-42);
}

float calculate_distance(t_map *map)
{
    t_float_vector    wall;
    float ret;
    t_float_vector       distance;
    t_float_vector  ray;

    ray = map->person;
    while (1)
    {
        wall = choose_walls(ray, map->direction);
        ret = check_walls(&distance, &ray, &wall, map); 
        if  (ret >= 0)
            return(ret);
        
    }
    return(wall.x);
}

// int main(void)
// {
//     t_float_vector person;
//     person.x = 3;
//     person.y = 2;
    

//     t_float_vector direction;
//     direction.x = -1;
//     direction.y = 2;
//     return (0);
// }








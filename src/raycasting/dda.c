//#include "cub3d.h"
#include <math.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct s_float_vector
{
	float	x;
	float	y;
}				t_float_vector;


int choose_wall(float person, float direction)
{
    if ((float) (int) person == person)
    {
        if(direction < 0)
            return (person - 1);
        if(direction >= 0)
            return (person + 1);
    }
    else
    {
        if(direction < 0)
            return (floor(person));
        if(direction >= 0)
            return (ceil(person));
    }
    return(-42);
}

t_vector choose_walls(t_float_vector person, t_float_vector direction)
{
    t_vector walls;

    walls.x = choose_wall(person.x, direction.x);
    walls.y = choose_wall(person.y, direction.y);

    return (walls);
}

float   calculate_distance(float  wall, float person)
{
    float   distance;

    if ( wall > person)
    {
        distance = wall - person;
        return(distance);
    }
    distance = person - wall;
    return(distance);
}

t_float_vector   calculate_point_wall(t_float_vector distance, t_float_vector direction, int  x_y)
{

    if(x_y == 0)
    {
        distance.y = (distance.x * direction.y ) / direction.x;
    }
    if (x_y == 1)
    {
        distance.x = (distance.y * direction.x) / direction.y;
    }
    // printf("\n\ncalculate point.x  %f     calculate point.y  %f\n\n", distance.x, distance.y);
    // if(direction.x < 0)
    // {
    //     distance.x *= -1;
    // }

    // if(direction.y < 0)
    //     distance.y *= -1;
    return(distance);
}

int verif_with_walls(t_float_vector person, t_vector walls)
{
    if(floor(person.x) == walls.x && floor(person.y) == walls.y)
    {
        //sleep(2);
        return(1);
    }
    return(0);
}

t_vector  hit_ray_wall(t_float_vector direction, t_float_vector person, int *x_y)
{
    char map[5][9] = {
        "11111111",
        "10000001",
        "10111101",
        "10000001",
        "11111111"
    };
    t_float_vector  person_aux;
    t_vector walls;
    t_vector    check;
    t_float_vector   point_wall;
    t_float_vector   distance;
    person_aux = person;
    while (1)
    {
        *x_y = 1;
        walls = (choose_walls(person, direction));
        printf("choose walls %d %d\n", walls.x, walls.y);
        while(*x_y >= 0)
        {
            if(*x_y == 0)
                distance.x = calculate_distance((float)walls.x, person.x);
            else
                distance.y = calculate_distance((float)walls.y, person.y);
            distance = calculate_point_wall(distance, direction, *x_y);
            person_aux.x += distance.x;
            person_aux.y += distance.y;
            printf("distance   %f %f\n", person_aux.x, person_aux.y);
            
            if(verif_with_walls(person_aux, walls))
            {
                check.x = (int)floor(person_aux.x);
                check.y = (int)floor(person_aux.y);
                //printf("entro   %f %f\n", person_aux.x, person_aux.y);
                person = person_aux;
                if(map[check.x][check.y] == '1')
                {
                    return(check);
                }

            }
            else
            {
                person_aux = person;
            }
       
            *x_y -= 1;
        }

    }

}
//0 = X
//1 = Y

int   choose_point_wall(float direction, int wall)
{
    if(direction < 0)
    {
        return((wall + 1));
    }
    return((wall ));
}
float   calculate_hit_point(t_vector    hit_index, t_float_vector person, t_float_vector direction, int x_y)
{
    t_float_vector  distance;
    t_float_vector  cathetus;
    float           hypotenuse;
    float           wall;

    // printf("\n\nhit index %d %d\n", hit_index.x, hit_index.y);
    if(x_y == 0)
    {
        wall = choose_point_wall(direction.x, hit_index.x);
        cathetus.x = distance.x = calculate_distance(wall, person.x);
    }
    else
    {
        wall = choose_point_wall(direction.y, hit_index.y);
        cathetus.y = distance.y = calculate_distance(wall, person.y);
    }
    // printf("distancia %f %f\n", distance.x, distance.y);
    distance = calculate_point_wall(distance, direction, x_y);
    distance.x += person.x;
    distance.y += person.y;
    // printf("calculate point wall %f %f\n", distance.x, distance.y);
    if(x_y == 0)
    {
        cathetus.y = calculate_distance(person.y, fabs(distance.y));
    }
    else
    {
        cathetus.x = calculate_distance(person.x, fabs(distance.x));
    }
    hypotenuse = sqrt(cathetus.x * cathetus.x + cathetus.y * cathetus.y); 
    return(hypotenuse);
}

int main()
{
    float   hypotenuse;
    t_vector hit_index;
    t_float_vector person;
    person.x = 3.5;
    person.y = 1.5;
    int x_y;
    
    x_y = 1;
    t_float_vector direction;
    direction.x = -1;
    direction.y = 2;

    t_float_vector wall;
    hit_index = hit_ray_wall( direction, person, &x_y);
    printf("hit index %d %d\n", hit_index.x, hit_index.y);
    //hypotenuse = calculate_hit_point(hit_index, person, direction, x_y);
    return(0);
}   
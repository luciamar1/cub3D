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


t_vector choose_walls(t_float_vector person)
{
    t_vector walls;

    if ((float) (int) person.x == person.x)
    {
        if(person.x > 0)
            walls.x = person.x + 1;
        else if(person.x < 0)
            walls.x = person.x - 1;
        else
            walls.x = -42;
        printf("soy entero %d   %d\n", walls.x, person.x);
    }
    else
    {
        if(person.x > 0)
            walls.x = ceil(person.x);
        else if(person.x < 0)
            walls.x -= floor(person.x);
        else
            walls.x = -42;
        printf("soy decimal %d\n", walls.x);
    }

    if ((float) (int) person.y == person.y)
    {
        if(person.y > 0)
            walls.y = person.y + 1;
        else if(person.y < 0)
            walls.y = person.y - 1;
        else
            walls.y = -42;
        printf("soy entero %d\n", walls.y);
    }
    else
    {
        if(person.y > 0)
            walls.y = ceil(person.y);
        else if(person.y < 0)
            walls.y -= floor(person.y);
        else
            walls.y = -42;
        printf("soy decimal %d\n", walls.y);
    }
    return (walls);
}

float   calculate_distance(int  wall, float person)
{
    float   distance;

    if (wall > person)
        return(wall - person);
    return(person - wall);
}

t_float_vector   calculate_point_wall(t_float_vector distance, t_float_vector direction, int  x_y)
{

    if(x_y == 0)
    {
        distance.y = distance.x * direction.y / direction.x;
    }
    if (x_y == 1)
    {
        distance.x = distance.y * direction.y / direction.y;
    }
    return(distance);
}

t_float_vector  hit_ray_wall(char **map, t_float_vector direction, t_float_vector person)
{
    t_vector walls;
    int counter;
    t_float_vector   point_wall;
    t_float_vector   distance;
    while (1)
    {
        counter = 1;
        walls = (choose_walls(direction));
        printf("walls %d %d\n", walls.x, walls.y);
        while(counter >= 0)
        {
            if(counter == 0)
                distance.x = calculate_distance(walls.x, person.x);
            else
                distance.y = calculate_distance(walls.y, person.y);
            distance = calculate_point_wall(distance, direction, counter);

        }

    }

}

int main()
{
   char map[5][9] = {
    "11111111",
    "10000001",
    "10000001",
    "10000001",
    "11111111"
    };
    t_float_vector person;
    person.x = 1;
    person.y = 1;

    t_float_vector direction;
    direction.x = -1;
    direction.y = 2;

    t_float_vector wall;
    hit_ray_wall(map, direction, person);
    return(0);
}
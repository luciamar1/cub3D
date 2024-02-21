//#include "cub3d.h"
#include <math.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct s_double_vector
{
	double	x;
	double	y;
}				t_double_vector;

t_double_vector calculate_step(t_double_vector direction)
{
    t_double_vector    step;

    if (direction.x < 0)
    {
        direction.x *= -1;
        step.x = -1;
    }
    else
        step.x = 1;
    step.y = direction.y / direction.x;
    return (step);
}

t_vector    verif_ray(char map[][9], t_vector person, t_double_vector direction)
{
    t_double_vector step;
    t_double_vector double_vision;

    int counter;

    counter = 1;
    step = calculate_step(direction);
    printf("step x == %f\nstep y == %f\n", step.x, step.y);
    double_vision.x = (double) person.x;
    double_vision.y = (double) person.y;
    while(map[person.x][person.y])
    {
        printf("\n\nperson x == %d\nperson y == %d\n", person.x, person.y);
        if (map[person.x][person.y] == '1')
            return(person);
        double_vision.x += step.x ;
        double_vision.y += step.y;
        person.x = floor(double_vision.x);
        person.y = floor(double_vision.y);
        printf("\n\nluego person x == %d\nluego person y == %d\n", person.x, person.y);
    }
    return (person);
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
    t_vector person;
    person.x = 3;
    person.y = 2;

    t_double_vector direction;
    direction.x = 3;
    direction.y = 2;

    t_vector pared;
    pared = verif_ray(map, person, direction);

    printf("x == %d\n", pared.x);
    printf("y == %d\n", pared.y);
    return(0);
}
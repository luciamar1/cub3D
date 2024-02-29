//#include "cub3d.h"
#include <math.h>
# include <unistd.h>
# include <stdio.h>

//0 = X
//1 = Y
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



int   choose_point_wall(float direction, int wall)
{
    if(direction < 0)
    {
        printf("WALLLL ======= %d   %d\n", (wall + 1), wall);
        return((wall + 1));
    }
    printf("WALLLL ======= %d    %d\n", (wall - 1), wall);
    return((wall - 1));
}

float   calculate_hit_point(t_vector    hit_index, t_float_vector person, t_float_vector direction, int x_y)
{
    t_float_vector  distance;
    t_float_vector  cathetus;
    float           hypotenuse;


    printf("hit index == %d %d     %d\n", hit_index.x, hit_index.y, x_y);
    if(x_y == 0)
    {
        cathetus.x = distance.x = calculate_distance((float)choose_point_wall(direction.x, hit_index.x), person.x);
        printf("\n\ndistancia persona pared %f\n", cathetus.x);
    }
    else
    {
        cathetus.y = distance.y = calculate_distance((float)choose_point_wall(direction.y, hit_index.y), person.y);
        printf("\n\ndistancia persona pared %f\n", cathetus.y);
    }
    distance = calculate_point_wall(distance, direction, x_y);
    if(x_y == 0)
    {
        cathetus.y = calculate_distance(person.y, fabs(distance.y));
        printf("cateto x = %f  cateto y = %f \n\n", cathetus.x, cathetus.y);
    }
    else
    {
        cathetus.x = calculate_distance(person.x, fabs(distance.x));
        printf("cateto x = %f  cateto y = %f \n\n", cathetus.x, cathetus.y);
    }
    hypotenuse = sqrt(cathetus.x * cathetus.x + cathetus.y * cathetus.y); 
    return(hypotenuse);
}
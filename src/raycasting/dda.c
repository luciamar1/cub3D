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
void print_biarr(char **str)
{
	while(*str)
	{
		if(**str)
			printf("str == %s\n", *str);
		str++;
	}
}

void    print_vector(t_vector vector)
{
    printf("vector  %d %d\n", vector.x, vector.y);
}

void    print_fvector(t_float_vector vector)
{
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
    return (wall);
}

float   calc_distance(float person, float   wall)
{
    // if (person >= wall)
    //     return (person - wall);

        return (wall - person);
    
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
        printf("HOLAAA\n");
        vector_distance.x = (vector_distance.y * direction.x) / direction.y;
        printf("ADIOS\n");
    }
    return (vector_distance);
}
t_vector    what_verif(t_float_vector ray, t_float_vector   direction)
{
    t_vector    verif;

    verif.x = (int)floor(ray.x);
    verif.y = (int)floor(ray.y);
    printf("what verif\n");
    print_vector(verif);
    // if(direction.x > 0)
    //     verif.x = verif.x + 1;
    // if(direction.y > 0)
    //     verif.y = verif.y + 1;
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
    printf("\n\n");
    return (verif);
}

t_vector  verif_mendi(t_float_vector person, t_float_vector direction)
{
    t_vector    mendi;


    if((float) (int) person.x == person.x  && (float) (int) person.y == person.y)
    {
        printf("jujuiJUIJUI\n");
        if(direction.x == 0)
            mendi.x = (int)floor(person.x);
        if(direction.y == 0)
            mendi.y = (int)floor(person.y);
        if(direction.x < 0)
            mendi.x = person.x - 1;
        if(direction.y < 0)
            mendi.y = person.y - 1;
        if(direction.x > 0)
            mendi.x = person.x + 1;
        if(direction.y > 0)
            mendi.y = person.y + 1;
        print_fvector(person);
        return(mendi);
        
    }

        if(direction.x == 0)
            mendi.x = (int)floor(person.x);
        if(direction.x < 0)
            mendi.x = (int)floor(person.x);
        if(direction.y < 0)
            mendi.y = (int)floor(person.y);

        if(direction.y == 0)
            mendi.y = (int)floor(person.y);
        if(direction.x >  0)
            mendi.x = (int)ceil(person.x);
        if(direction.y >  0)
            mendi.y = (int)ceil(person.y);
        print_fvector(person);
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
    printf("                              person %f\n", person.x);
    printf("                              distance %f\n", distance.x);
    person.x += distance.x;
    person.y += distance.y;

    printf("walls\n");
    print_fvector(wall);

    printf("\n                                       verif person walls\n");
    print_fvector(person);
    printf("\n\n\n");
    sleep(1);
    verif = verif_gg(person, distance);
    printf("VERIFFFFF\n");
    print_vector(verif);
    if (verif.x == wall.x && verif.y == wall.y)
        return(1);
    return (0);
}

float   calc_hypotenuse(t_float_vector person, t_float_vector origin)
{
    float   cathetus_a;
    float   cathetus_b;
    float   hypothenuse;

    printf("\n\n");
    printf("hit\n");
    print_fvector(person);
    printf("origin\n");
    print_fvector(origin);
    cathetus_a = calc_distance(person.x, origin.x);
    cathetus_b = calc_distance(person.y, origin.y);
    hypothenuse = sqrt(cathetus_a * cathetus_a + cathetus_b * cathetus_b); 
    printf("cateto a == %f\n", cathetus_a);
    printf("cateto b == %f\n", cathetus_b);
    printf("hipotenusa\n");
    printf("%f\n", hypothenuse);
    return (hypothenuse);
}



float calculate_distance(t_float_vector person, t_float_vector direction)
{
        int i;
        int pepe;
    t_float_vector    wall;
    int         x_y;
    t_float_vector       distance;
    t_vector        verif;
    t_float_vector  origin_vector;
    t_float_vector  aux_person;


    origin_vector = person;

    char map[5][9] = {
        "11111111",
        "10000111",
        "10000111",
        "10000001",
        "11111111",
    };

         map[(int)(person.x)][(int)(person.y)] = 'P';
    while (1)
    {
        x_y = 1;
        wall = choose_walls(person, direction);
        while (x_y >= 0)
        {
            distance = vector_distance(person, wall, direction, x_y);
            printf("distancia\n");
            print_fvector(distance);
            printf("\n\n");
            if(verif_if_walls(person, distance, wall))
            {
                printf("ENTRO\n");
         
                person.x = person.x + distance.x;
                person.y = person.y + distance.y;
                printf("PERSON\n");
                print_fvector(person);
               // verif = what_verif(person, direction);
                verif = verif_mendi(person, direction);
                printf("mendi\n");
                print_vector(verif);
                //print_fvector(person);
                if (map[verif.x][verif.y] == '1')
                {
                    printf("punto hit\n");
                    print_fvector(person);
                    if(direction.x == 0 || direction.y == 0)
                    {
                        printf("hola %f  %f\n", origin_vector.x - person.x, origin_vector.y - person.y);
                        return(fabs((origin_vector.x - person.x) + (origin_vector.y - person.y)));
                    }
                    return (calc_hypotenuse(person, origin_vector));
                }
                if(person.x == 1 && person.y == 6)
                    printf("WAAAAAAAAAAAAAAAAAAAAA            1 6        %c\n", map[(int)floor(person.x)][(int)floor(person.y)]);
                x_y = 1;
                map[(int)(person.x)][(int)(person.y)] = 'V';
                i = 0;
                pepe = 5;
                while(pepe --)
                {     
                        printf("map == %s\n", map[i]);
                        i ++;
                }
                        printf("\n\n");
                break ;
            }
            x_y  --;
        }
    }
    return(wall.x);
}

int main(void)
{
    t_float_vector person;
    person.x = 3;
    person.y = 2;
    

    t_float_vector direction;
    direction.x = -1;
    direction.y = 2;
    printf("distance %f\n", calculate_distance(person, direction));
    return (0);
}


























































// int choose_wall(float person, float direction)
// {
//     if ((float) (int) person == person)
//     {
//         if(direction < 0)
//             return (person - 1);
//         if(direction >= 0)
//             return (person + 1);
//     }
//     else
//     {
//         if(direction < 0)
//             return (floor(person));
//         if(direction >= 0)
//             return (ceil(person));
//     }
//     return(-42);
// }

// t_vector choose_walls(t_float_vector person, t_float_vector direction)
// {
//     t_vector walls;

//     walls.x = choose_wall(person.x, direction.x);
//     walls.y = choose_wall(person.y, direction.y);

//     return (walls);
// }

// float   calculate_distance(float  wall, float person)
// {
//     float   distance;

//     if ( wall > person)
//     {
//         distance = wall - person;
//         return(distance);
//     }
//     distance = person - wall;
//     return(distance);
// }

// t_float_vector   calculate_point_wall(t_float_vector distance, t_float_vector direction, int  x_y)
// {

//     if(x_y == 0)
//     {
//         distance.y = (distance.x * direction.y ) / direction.x;
//     }
//     if (x_y == 1)
//     {
//         distance.x = (distance.y * direction.x) / direction.y;
//     }
//     // printf("\n\ncalculate point.x  %f     calculate point.y  %f\n\n", distance.x, distance.y);
//     // if(direction.x < 0)
//     // {
//     //     distance.x *= -1;
//     // }

//     // if(direction.y < 0)
//     //     distance.y *= -1;
//     return(distance);
// }

// int verif_with_walls(t_float_vector person, t_vector walls)
// {
//     if(floor(person.x) == walls.x && floor(person.y) == walls.y)
//     {
//         /(2);
//         return(1);
//     }
//     return(0);
// }

// t_vector  hit_ray_wall(t_float_vector direction, t_float_vector person, int *x_y)
// {
//     char map[5][9] = {
//         "11111111",
//         "10000001",
//         "10111101",
//         "10000001",
//         "11111111"
//     };
//     t_float_vector  person_aux;
//     t_vector walls;
//     t_vector    check;
//     t_float_vector   point_wall;
//     t_float_vector   distance;
//     person_aux = person;
//     while (1)
//     {
//         *x_y = 1;
//         walls = (choose_walls(person, direction));
//         printf("choose walls %d %d\n", walls.x, walls.y);
//         while(*x_y >= 0)
//         {
//             if(*x_y == 0)
//                 distance.x = calculate_distance((float)walls.x, person.x);
//             else
//                 distance.y = calculate_distance((float)walls.y, person.y);
//             distance = calculate_point_wall(distance, direction, *x_y);
//             person_aux.x += distance.x;
//             person_aux.y += distance.y;
//             printf("distance   %f %f\n", person_aux.x, person_aux.y);
            
//             if(verif_with_walls(person_aux, walls))
//             {
//                 check.x = (int)floor(person_aux.x);
//                 check.y = (int)floor(person_aux.y);
//                 //printf("entro   %f %f\n", person_aux.x, person_aux.y);
//                 person = person_aux;
//                 if(map[check.x][check.y] == '1')
//                 {
//                     return(check);
//                 }

//             }
//             else
//             {
//                 person_aux = person;
//             }
       
//             *x_y -= 1;
//         }

//     }

// }
// //0 = X
// //1 = Y

// int   choose_point_wall(float direction, int wall)
// {
//     if(direction < 0)
//     {
//         return((wall + 1));
//     }
//     return((wall ));
// }
// float   calculate_hit_point(t_vector    hit_index, t_float_vector person, t_float_vector direction, int x_y)
// {
//     t_float_vector  distance;
//     t_float_vector  cathetus;
//     float           hypotenuse;
//     float           wall;

//     // printf("\n\nhit index %d %d\n", hit_index.x, hit_index.y);
//     if(x_y == 0)
//     {
//         wall = choose_point_wall(direction.x, hit_index.x);
//         cathetus.x = distance.x = calculate_distance(wall, person.x);
//     }
//     else
//     {
//         wall = choose_point_wall(direction.y, hit_index.y);
//         cathetus.y = distance.y = calculate_distance(wall, person.y);
//     }
//     // printf("distancia %f %f\n", distance.x, distance.y);
//     distance = calculate_point_wall(distance, direction, x_y);
//     distance.x += person.x;
//     distance.y += person.y;
//     // printf("calculate point wall %f %f\n", distance.x, distance.y);
//     if(x_y == 0)
//     {
//         cathetus.y = calculate_distance(person.y, fabs(distance.y));
//     }
//     else
//     {
//         cathetus.x = calculate_distance(person.x, fabs(distance.x));
//     }
//     hypotenuse = sqrt(cathetus.x * cathetus.x + cathetus.y * cathetus.y); 
//     return(hypotenuse);
// }

// int main()
// {
//     float   hypotenuse;
//     t_vector hit_index;
//     t_float_vector person;
//     person.x = 3.5;
//     person.y = 1.5;
//     int x_y;
    
//     x_y = 1;
//     t_float_vector direction;
//     direction.x = -1;
//     direction.y = 2;

//     t_float_vector wall;
//     hit_index = hit_ray_wall( direction, person, &x_y);
//     printf("hit index %d %d\n", hit_index.x, hit_index.y);
//     //hypotenuse = calculate_hit_point(hit_index, person, direction, x_y);
//     return(0);
// }   
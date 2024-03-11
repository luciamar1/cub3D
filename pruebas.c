#include "./libft/libft.h"
#include <stdio.h>
#include <math.h>

// int verify_line(char *str)
// {
//     int ret;

//     ret = 0;
//     while(*str)
//     {
//         if(*str == '1')
//             ret = 1;
//         str ++;
//     }
//     return(ret);
// }

// int verify_colum(char **str, int y)
// {
//     int counter;
//     int ret;

//     ret = 0;
//     counter = 0;
//     while (str[counter])
//     {
//         if(ft_strlen(str[counter]) > (size_t)y && str[counter][y] == '1')
//             ret = 1;
//         printf("x y == %c     %d     %d\n", str[counter][y], counter, y);
//         counter ++;
//     }
//     printf("\n\n");
//     return (ret);
// }

// int verify_if_close(char **map)
// {
//     int x;
//     int y;

//     x = 0;
//     y = 0;
//     while (map[x])
//     {
        
//         if (!verify_line(map[x]))
//         {
//             printf("line\n");
//             return (0);
//         }
//         x ++;
//     }
//     while (map[0][y])
//     {
//         if (!verify_colum(map, y))
//         {
//             printf("column\n");
//             return (0);
//         }
//         y ++;
//     }
//     return (1);
// }
// int is_space(char character)
// {
//     int ret;

//     ret = 0;
//     if (character == 32 || (character >= 9 && character <= 13))
//         ret = 1;
//     return (ret);
// }

// int	isdigit_str(char *str)
// {
// 	int counter;
//     int status;

//     status = 0,
// 	counter = 0;
//     while(str[counter]) 
// 	{
// 		while (!ft_isdigit(str[counter]))
// 		{	
//             status = 1;
// 			if(is_space(str[counter]) && !str[counter + 1])
// 			{
// 				return(1);
// 			}
//             counter ++;
// 		}
//         if (status)
//             return(0);
//         counter++;
//     }
//     return(1);

// }

int main(void)
{


        printf("floor %f\n", floor(3.00));
        printf("ceil %f\n", ceil(3.00));
    return(1);
}
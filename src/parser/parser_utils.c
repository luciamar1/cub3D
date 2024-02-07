#include "cub3d.h"

int is_space(char character)
{
    int ret;

    ret = 0;
    if (character == 32 || (character >= 9 && character <= 13))
        ret = 1;
    return (ret);
}

int move_to_space(char **str)
{
    int ret;

    ret = 0;
    while(*(*str) == 32 || (*(*str) >= 9 && *(*str) <= 13))
    {
        ret = 1;
        (*str) ++;
    }
    return (ret);
}


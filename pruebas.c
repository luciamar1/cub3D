#include "./libft/libft.h"
#include <stdio.h>


int is_space(char character)
{
    int ret;

    ret = 0;
    if (character == 32 || (character >= 9 && character <= 13))
        ret = 1;
    return (ret);
}

int	isdigit_str(char *str)
{
	int counter;
    int status;

    status = 0,
	counter = 0;
    while(str[counter]) 
	{
		while (!ft_isdigit(str[counter]))
		{	
            status = 1;
			if(is_space(str[counter]) && !str[counter + 1])
			{
				return(1);
			}
            counter ++;
		}
        if (status)
            return(0);
        counter++;
    }
    return(1);

}

int main(void)
{
    if(isdigit_str("567   "))
        printf("atoi %d\n", ft_atoi("678  "));
    return(1);
}
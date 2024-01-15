#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
#include "libft.h"



//parser
int parser(int argc, char **argv);


//utils
int	ft_str_rev_n_cmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin_chetao(char **s1, char **s2);
void print_biarr(char **str);

#endif
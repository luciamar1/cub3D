#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
#include "libft.h"

typedef struct s_textures
{   
    int no;
    int so;
    int we;
    int ea;
} t_textures;

typedef struct s_rgb
{
    int r;
    int g;
    int b;
} t_rgb;

typedef struct s_colors
{
    t_rgb   ceiling;
    t_rgb   floor;
} t_colors;

typedef struct s_doc
{
    t_colors    colors;
    t_textures  textures;
} t_doc;


//parser
int parser(int argc, char **argv);


//utils
int	ft_str_rev_n_cmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin_chetao(char **s1, char **s2);
void print_biarr(char **str);
int	ft_atoi_chetao(const char *str, int *error);
void	print_doc(t_doc doc);
int	isdigit_str(char *str);

#endif
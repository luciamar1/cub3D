#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
#include "libft.h"
# define SIZE 32

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct s_window {
	void		*reference;
	t_vector	size;
}				t_window;

typedef struct s_minilib
{
	void		*mlx_pointer;
	t_window	*window;
}				t_minilib;

typedef struct s_textures
{   
    void    *no;
    void    *so;
    void    *we;
    void    *ea;
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
    t_minilib   program;
    char        **map;
} t_doc;


//parser
t_doc   parser(int argc, char **argv, int *err);
t_doc check_create_document(char **str_doc, int *err);
int    try_colors(char   *str_doc, int *err_doc, t_colors *doc_rgb);
int check_map(char **map);
int is_space(char character);
int move_to_space(char **str);
char **read_document(char *extension);

//utils
void	free_biarr(char **fr);
char	*ft_strjoin_better(char **s1, char **s2);
void print_biarr(char **str);
int	isdigit_str(char *str);
void	print_doc(t_doc doc);
char **strdup_bi(char **str);
void    print_error(char *message);
int	ft_atoi_better(const char *str, int *error);

void    put_value_color(t_colors *colors, int value, char   type);
int	ft_str_rev_n_cmp(const char *s1, const char *s2, size_t n);

#endif
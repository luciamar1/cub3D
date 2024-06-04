#ifndef UTILS_H
# define UTILS_H


#include "libft.h"
# include "parser/parser.h"
#include "../cub3d.h"


//utils
void	free_biarr(char **fr);
char	*ft_strjoin_better(char **s1, char **s2);
void print_biarr(char **str);
int	isdigit_str(char *str);
void	print_doc(t_doc doc);
char **strdup_bi(char **str);
void    print_error(char *message);
int	ft_atoi_better(const char *str, int *error);
int	is_digit_space_str(char *str);
void	**alloc_biarr(int dim1, int dim2);


#endif

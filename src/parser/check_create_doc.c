#include "cub3d.h"

void    create_map(char **str_doc, int *err, t_doc *doc)
{
    str_doc ++;
    doc->map.bimap = strdup_bi(str_doc);
    if(!doc->map.bimap)
    {
        print_error("malloc error\n");
        *err = 1;
    }
    return ;
}

t_doc check_create_document(char **str_doc, int *err)
{
    t_doc   doc;
    int     err_doc;
    int     colors;
    int     text;
    int     check_if_create[6];
    
    doc.map.bimap = ((ft_bzero(check_if_create, sizeof(int) * 6)), NULL);
    doc.program.mlx_pointer = ((colors = 0), (text = 0), mlx_init());
    if (!doc.program.mlx_pointer)
		return (print_error("mlx_init fail\n"), (*err = 1), doc);
    while (*str_doc)
    {
        colors += ((err_doc = 0), try_colors(*str_doc, &err_doc, &(doc), check_if_create));
        if(err_doc == -1)
            return (print_error("error in colors\n"), (*err = 1), doc);
        text += try_textures(*str_doc, &err_doc, &doc, check_if_create);
        if(err_doc == -1)
            return (print_error("error in textures\n"), (*err = 1), doc);
        if (err_doc == 6)
            return (print_error("invalid content in doc\n"), (*err = 1), doc);
        if(colors == 2 && text == 4)
            return((create_map(str_doc, err, &doc)), doc);
        str_doc++;
    }
    return (*err = 1, print_error("incomplete doc\n"), doc);
}

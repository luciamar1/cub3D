#include "cub3d.h"

void    *check_textures(char   *str_doc, int *err_doc, t_doc *doc, int *textures)
{
    void    *img;
    int     size;

    size = SIZE;
    str_doc += 2;
    move_to_space(&str_doc);
    img = mlx_xpm_file_to_image(doc->program.mlx_pointer, str_doc, &size, &size);
    if (!img)
        return((*err_doc = -1), img);
    *textures = 1;
    return(img);
}

int clasificate_textures(char   *str_doc, int *err_doc, t_doc *doc, int *textures)
{       
    if(!ft_strncmp(str_doc, "NO ", 3) && !textures[2])
        return ((doc->textures.no = check_textures(str_doc, err_doc, doc, &textures[2])), 1);
    else
        *err_doc += 1;
    if(!ft_strncmp(str_doc, "SO ", 3) && !textures[3])
        return ((doc->textures.so = check_textures(str_doc, err_doc, doc, &textures[3])), 1);
    else
        *err_doc += 1;
    if(!ft_strncmp(str_doc, "WE ", 3) && !textures[4])
        return ((doc->textures.we = check_textures(str_doc, err_doc, doc, &textures[4])), 1);
    else
        *err_doc += 1;
    if(!ft_strncmp(str_doc, "EA ", 3) && !textures[5])
        return ((doc->textures.ea = check_textures(str_doc, err_doc, doc, &textures[5])), 1);
    else
        *err_doc += 1;
    return(0);
}

int try_textures(char   *str_doc, int *err_doc, t_doc *doc, int *textures)
{
    int ret;

    move_to_space(&str_doc);
    ret = clasificate_textures(str_doc, err_doc, doc, textures);
    return (ret);
}
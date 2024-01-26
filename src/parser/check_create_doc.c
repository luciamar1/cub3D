#include "../../cub3d.h"


int  check_textures(char *str, int *err, char *orientation, int *check)
{
    int fd;

    fd = 0;
    move_to_space(&str);
    if (!ft_strncmp(str, orientation, 2) && is_space(str[2]))
    {
        str += 2;
        move_to_space(&str);
        fd = open(str, O_RDONLY);
        if (fd < 0)
            return((*err = -1), fd);
        *check = 1;
    }
    else
        err ++;
    return(fd);
}


int    try_textures(char   *str_doc, int *err_doc, t_textures *doc_texture)
{
    int     check;
    int     path_texture;

    check = 0;
    path_texture = check_textures(str_doc, err_doc, "NO", &check);
    if (check)
        return ((doc_texture->no = path_texture), 1);
    path_texture = check_textures(str_doc, err_doc, "SO", &check);
    if (check)
        return ((doc_texture->so = path_texture), 1);
    path_texture = check_textures(str_doc, err_doc, "WE", &check);
    if (check)
        return ((doc_texture->we = path_texture), 1);
    path_texture = check_textures(str_doc, err_doc, "EA", &check);
    if (check)
        return((doc_texture->ea = path_texture), 1);
    return(0);
}

t_doc check_create_document(char **str_doc, int *err)
{
    t_doc   doc;
    int     err_doc;
    int     colors;
    int     textures;
    
    colors = (textures = 0), 0;
    while(*str_doc)
    {
        err_doc = 0;
        if(ft_isascii(**str_doc))
        {
            colors += try_colors(*str_doc, &err_doc, &(doc.colors));
            if(err_doc == -1)
                return(print_error("error in colors\n"), (*err = 1), doc);
            textures += try_textures(*str_doc, &err_doc, &(doc.textures));
            if(err_doc == -1)
                return(print_error("error in textures\n"), (*err = 1), doc);
            is_comment(err, *str_doc);
            if (*err == 7)
                return (print_error("invalid content in doc\n"), (*err = 1), doc);
        }
        else
            return ((*err = 1), doc);
        str_doc++;
        if(colors == 2 && textures == 4)
        {
            doc.map = strdup_bi(str_doc);
            if(!doc.map)
                return((*err = 1), doc);
            return(doc);
        }  
    }
    return(doc);
}

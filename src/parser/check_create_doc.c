#include "cub3d.h"

void    *check_textures(char   *str_doc, int *err_doc, t_doc *doc)
{
    void    *img;
    int     size;

    size = SIZE;
    img = 0;
    str_doc += 2;
    move_to_space(&str_doc);
    img = mlx_xpm_file_to_image(doc->program.mlx_pointer, str_doc, &size, &size);
    if (!img)
        return((*err_doc = -1), img);
    return(img);
}

int clasificate_textures(char   *str_doc, int *err_doc, t_doc *doc, int *textures)
{       
    if(!ft_strncmp(str_doc, "NO ", 3) && !textures[0])
        return ((doc->textures.no = check_textures(str_doc, err_doc, doc)), 1);
    else
        *err_doc += 1;
    if(!ft_strncmp(str_doc, "SO ", 3) && !textures[1])
        return ((doc->textures.so = check_textures(str_doc, err_doc, doc)), 1);
    else
        *err_doc += 1;
    if(!ft_strncmp(str_doc, "WE ", 3) && !textures[2])
        return ((doc->textures.we = check_textures(str_doc, err_doc, doc)), 1);
    else
        *err_doc += 1;
    if(!ft_strncmp(str_doc, "EA ", 3) && !textures[3])
        return ((doc->textures.ea = check_textures(str_doc, err_doc, doc)), 1);
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

void    create_map(char **str_doc, int *err, t_doc *doc)
{
    str_doc ++;
    doc->map = strdup_bi(str_doc);
    if(!doc->map)
        print_error("malloc error\n");
        *err = 1;
    return ;
}

t_doc check_create_document(char **str_doc, int *err)
{
    t_doc   doc;
    int     err_doc;
    int     colors;
    int     text;
    int     textures[4];
    

    doc.map = ((ft_bzero(textures, sizeof(int) * 4)), NULL);
    doc.program.mlx_pointer = ((colors = 0), (text = 0), mlx_init());
    if (!doc.program.mlx_pointer)
		return (print_error("mlx_init fail\n"), (*err = 1), doc);
    put_value_color(&doc.colors, -1, 't');
    while(*str_doc)
    {

        colors += ((err_doc = 0), try_colors(*str_doc, &err_doc, &(doc.colors)));
        if(err_doc == -1)
            return(print_error("error in colors\n"), (*err = 1), doc);
        text += try_textures(*str_doc, &err_doc, &(doc), textures);
        if(err_doc == -1)
            return(print_error("error in textures\n"), (*err = 1), doc);
        if (err_doc == 6)
            return (print_error("invalid content in doc\n"), (*err = 1), doc);
        if(colors == 2 && text == 4)
            return((create_map(str_doc, err, &doc)), doc);
        str_doc++;
    }
    return(doc);
}

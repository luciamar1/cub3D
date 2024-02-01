#include "../../cub3d.h"


void    *check_textures(char *str, int *err, char *orientation, int *check, t_doc *doc)
{
    void    *img;
    int     size;

    size = SIZE;
    img = 0;

    printf("orientacion == %s \n", orientation);
    move_to_space(&str);
    if (!ft_strncmp(str, orientation, 2) && is_space(str[2]))
    {
        str += 2;
        move_to_space(&str);
        img = mlx_xpm_file_to_image(doc->program.mlx_pointer, str, &size, &size);
        if (!img)
            return((*err = -1), img);
        *check = 1;
    }
    else
        (*err) ++;
    return(img);
}

char *clasificate_textures(int *textures, int *position, int *err_doc)
{
    //printf("%d %d %d %d\n", textures[0], textures[1], textures[2], textures[3]);
    if(!textures[0])
        return((*position = 0), "NO");
    else
        *err_doc += 1;
    if(!textures[1])
        return((*position = 1), "SO");
    else
        *err_doc += 1;
    if(!textures[2])
        return((*position = 2), "WE");
    else
        *err_doc += 1;
    if(!textures[3])
        return((*position = 3), "EA");
    else
        *err_doc += 1;
    return(NULL);
}

int try_textures(char   *str_doc, int *err_doc, t_doc *doc, int *textures)
{
    int     check;
    void    *path_texture;
    char    *orientation;
    int     position;

    check = 0;
    position  = 0;
    orientation = clasificate_textures(textures, &position, err_doc);
    if (orientation)
    {
        path_texture = check_textures(str_doc, err_doc, orientation, &check, doc);
        if (check)
        {
            textures[position] = 1;
            return ((doc->textures.no = path_texture), 1);
        }
    }
        return(0);
}

t_doc check_create_document(char **str_doc, int *err)
{
    t_doc   doc;
    int     err_doc;
    int     colors;
    int     text;
    int     textures[4];
    
    ft_bzero(textures, sizeof(int) * 4);
    doc.map = NULL;
    doc.program.mlx_pointer = ((colors = 0), (text = 0), mlx_init());
    if (!doc.program.mlx_pointer)
		return (print_error("mlx_init fail\n"), (*err = 1), doc);
    while(*str_doc)
    {
        err_doc = 0;
        colors += try_colors(*str_doc, &err_doc, &(doc.colors));
        if(err_doc == -1)
            return(print_error("error in colors\n"), (*err = 1), doc);
        text += try_textures(*str_doc, &err_doc, &(doc), textures);
        if(err_doc == -1)
            return(print_error("error in textures\n"), (*err = 1), doc);
        if (err_doc == 6)
            return (print_error("invalid content in doc\n"), (printf("strerr== %s\n", *str_doc)), (*err = 1), doc);
        printf("colors == %d,   txtures == %d\n", colors, text);
        if(colors == 2 && text == 4)
        {
            printf("entras\n");
            doc.map = strdup_bi(str_doc);
            if(!doc.map)
                return((*err = 1), doc);
            return(doc);
        }
        else
            *err = 1;
        str_doc++;
    }
    return(doc);
}

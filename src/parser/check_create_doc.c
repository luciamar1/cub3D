#include "../../cub3d.h"


void    *check_textures(char *str, int *err, char *orientation, int *check, t_doc *doc)
{
    void    *img;
    int     size;

    size = SIZE;
    img = 0;

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



int try_textures(char   *str_doc, int *err_doc, t_doc *doc, int *textures)
{
    int     check;
    void    *path_texture;

    check = 0;
    //printf("nums %d %d %d %d\n", textures[0], textures[1], textures[2], textures[3]);
    if(!textures[0])
    {
        path_texture = check_textures(str_doc, err_doc, "NO", &check, doc);
        if (check)
        {
            printf("pri\n");
            textures[0] = 1;
            return ((doc->textures.no = path_texture), 1);
        }
    }
    else
        *err_doc += 1;
        
    if(!textures[1])
    {
        path_texture = check_textures(str_doc, err_doc, "SO", &check, doc);
        if (check)
        {
            printf("seg\n");
            textures[1] = 1;
            return ((doc->textures.so = path_texture), 1);
        }
    }
    else
        *err_doc += 1;
    if(!textures[2])
    {
        path_texture = check_textures(str_doc, err_doc, "WE", &check, doc);
        if (check)
        {
            printf("text 2 == %d\n", textures[2]);
            printf("ter\n");
            textures[2] = 1;
            return ((doc->textures.we = path_texture), 1);
        }
    }
    else
        *err_doc += 1;
        
    if(!textures[3])
    {
        path_texture = check_textures(str_doc, err_doc, "EA", &check, doc);
        if (check)
        {
            printf("ter\n");
            textures[3] = 1;
            return((doc->textures.ea = path_texture), 1);
        }
    }
    else
        *err_doc += 1;
        

    return(0);
}

t_doc check_create_document(char **str_doc, int *err)
{
    t_doc   doc;
    int     err_doc;
    int     colors;
    int     text;
    int     textures[4] = {0, 0, 0, 0};
    
    //ft_bzero(textures, sizeof(int));
    colors = (text = 0), 0;
    doc.program.mlx_pointer = mlx_init();
    if (!doc.program.mlx_pointer)
		return (print_error("mlx_init fail\n"), (*err = 1), doc);
    while(*str_doc)
    {
        err_doc = 0;
        colors += try_colors(*str_doc, &err_doc, &(doc.colors));
        if(err_doc == -1)
            return(print_error("error in colors\n"), (*err = 1), doc);
        text += try_textures(*str_doc, &err_doc, &(doc), textures);
        //printf("err_doc == %d\n", err_doc);
        if(err_doc == -1)
            return(print_error("error in textures\n"), (*err = 1), doc);
        //is_comment(&err_doc, *str_doc);
        if (err_doc == 6)
            return (print_error("invalid content in doc\n"), (*err = 1), doc);
        if(colors == 2 && text == 4)
        {
            doc.map = strdup_bi(str_doc);
            if(!doc.map)
                return((*err = 1), doc);
            return(doc);
        }
        str_doc++;
        // else
        //     return((*err = 1), doc);
    }
    return(doc);
}

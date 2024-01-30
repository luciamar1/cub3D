#include "../../cub3d.h"

int check_extension(char *document)
{
    if(ft_str_rev_n_cmp(document, ".cub", 4))
        return(print_error("incorrect extension\n"), 0);
    return (1);
}

int is_space(char character)
{
    int ret;

    ret = 0;
    if (character == 32 || (character >= 9 && character <= 13))
        ret = 1;
    return (ret);
}

int move_to_space(char **str)
{
    int ret;

    ret = 0;
    while(*(*str) == 32 || (*(*str) >= 9 && *(*str) <= 13))
    {
        ret = 1;
        //printf("move %c\n", **str);
        (*str) ++;
    }
    return (ret);
}

int choose_rgb(t_rgb *colors, char *nums)
{
    int num;
    int err_atoi;

    err_atoi = 0;
    num = ft_atoi_chetao(nums, &err_atoi);
    if(err_atoi)
        return(0);
    if(num >= 0 && num <= 255)
    {
        if(!colors->r)
            colors->r = num;
        else if(!colors->g)
            colors->g = num;
        else if(!colors->b)
            colors->b = num;
        return(1);
    }
    return(0);
}
int    check_rgb(char **nums, int *err, t_rgb *color)
{
    int counter;

    counter = 0;
    while(*nums)
    {
        move_to_space(&(*nums));
        if(isdigit_str(*nums))
        {
            counter ++;
            if(counter > 3)
                return((*err = -1), 0);
            if(!choose_rgb(color, *nums))
                return((*err = -1), 0);
        }
        else
        {
            *err += 1;
            return (0);
        }
        nums ++;
    }
    return (0);
}

t_rgb    check_colors(char   *str, int *err, char cf, int *check)
{
    char    **nums;
    char    **aux;
    t_rgb   color;

    color.g = (color.r = 0), (color.b = 0), 0;
    nums = NULL;
    aux = NULL;
    move_to_space(&str);
    if ((*str == cf && is_space(str[1])))
    {
        str ++;
        move_to_space(&str);
        nums = ft_split(str, ',');
        if(!nums)
            return((*err = -1), color);
        aux = nums;
        check_rgb(nums, err, &color);
        free_biarr(aux);
        if(*err == -1)
            return(color);
        *check = 1;
    }
    else 
        *err += 1;
    return (color);
}


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

char **create_document(char *extension)
{
    char    *line_document;
    char    *new_line;
    int     fd;
    char    **doc;

    line_document = NULL;
    fd = open(extension, O_RDONLY);
	if (fd < 0)
		return (printf("the file can't be open\n"), NULL);
    while(1)
    {
        new_line = get_next_line(fd);
        if(!new_line)
            break;
        line_document = ft_strjoin_chetao(&line_document, &new_line);
        if(!line_document)
            return(NULL);
    }
    doc = ft_split(line_document, '\n');
    protect_free(line_document);
    return (doc); 
}

void    try_colors(char   *str_doc, int *err_doc, char cf, t_rgb *doc_rgb)
{
    int     check;
    t_rgb   rgb;

    check = 0;
    rgb = check_colors(str_doc, err_doc, cf, &check);
    if (check)
        *doc_rgb = rgb;

}

void    try_textures(char   *str_doc, int *err_doc, t_textures *doc_texture)
{
    int     check;
    int     path_texture;

    check = 0;
    path_texture = check_textures(str_doc, err_doc, "NO", &check);
    if (check)
    {
        doc_texture->no = path_texture;
        return ;
    }
    path_texture = check_textures(str_doc, err_doc, "SO", &check);
    if (check)
    {
        doc_texture->so = path_texture;
        return ;
    }
    path_texture = check_textures(str_doc, err_doc, "WE", &check);
    if (check)
    {
        doc_texture->we = path_texture;
        return ;
    }
    path_texture = check_textures(str_doc, err_doc, "EA", &check);
    if (check)
        doc_texture->ea = path_texture;
}

t_doc check_create_document(char **str_doc, int *err)
{
    t_doc   doc;
    int     err_doc;
    
    while(*str_doc)
    {
        err_doc = 0;
        if(ft_isascii(**str_doc))
        {
            try_colors(*str_doc, &err_doc, 'C', &(doc.colors.ceiling));
            if (err_doc == -1)
                return((*err = 1), doc);
            try_colors(*str_doc, &err_doc, 'F', &(doc.colors.floor));
            if(err_doc == -1)
                return((*err = 1), doc);
            try_textures(*str_doc, &err_doc, &(doc.textures));
            if(err_doc == -1)
                return((*err = 1), doc);
            if (*err == 6)
                return ((*err = 1), doc);
        }
        str_doc++;
    }
    return(doc);
}

int parser(int argc, char **argv)
{
    char    **strbi_doc;
    t_doc   doc;
    int     err;

    if(argc != 2)
        return(printf("incorrect number of arguments"), 0);
    if (!check_extension(argv[1]))
        return(0);
    strbi_doc = create_document(argv[1]);
    if(!strbi_doc)
        return(0);
    doc = check_create_document(strbi_doc, &err);
    if(strbi_doc)
        free_biarr(strbi_doc);
    print_doc(doc);
    if (err)
        return(0);
    return(1);
}
#include "../../cub3d.h"

int check_extension(char *document)
{
    if(ft_str_rev_n_cmp(document, ".cub", 4))
        return(printf("incorrect extension\n"), 0);
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


t_rgb    check_colors(char   *str, int *err, char cf)
{
    int     counter;
    t_rgb   color;
    char    **nums;

    counter = 0;
    color.r = 0;
    color.g = 0;
    color.b = 0;
    move_to_space(&str);
    //printf("\nstr == %c\n cf == %c\n is space = %d\n", *str, cf, is_space(str[1]));
    if ((*str == cf && is_space(str[1])))
    {
        str ++;
        move_to_space(&str);
        nums = ft_split(str, ',');
        if(!nums)
            return((*err = -1), color);

        while(*nums)
        {
            move_to_space(&(*nums));
            if(isdigit_str(*nums))
            {
                counter ++;
                if(counter > 3)
                    return((*err = -1), color);
                if(!choose_rgb(&color, *nums))
                    return((*err = -1), color);
            }
            else
                return(*err += 1, color);
            nums ++;
        }
    }
    else 
        *err += 1;
    return (color);
}


int  check_textures(char *str, int *err, char *orientacion)
{
    int fd;

    fd = 0;
    move_to_space(&str);
    if (!ft_strncmp(str, orientacion, 2) && is_space(str[1]))
    {
        fd = open(str, O_RDONLY);
        if (fd < 0)
            return((*err = -1), fd);
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
    }
    doc = ft_split(line_document, '\n');
    free(line_document);
    return (doc); 
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
            doc.colors.ceiling = check_colors(*str_doc, &err_doc, 'C');
            if(err_doc == -1)
                return((*err = 1), doc);
            printf("   color ceiling == %d, %d , %d\n", doc.colors.ceiling.r, doc.colors.ceiling.g, doc.colors.ceiling.b);
            doc.colors.floor = check_colors(*str_doc, &err_doc, 'F');
            if(err_doc == -1)
                return((*err = 1), doc);
            doc.textures.ea = check_textures(*str_doc, &err_doc, "EA");
            if(err_doc == -1)
                return((*err = 1), doc);
            doc.textures.no = check_textures(*str_doc, &err_doc, "NO");
            if(err_doc == -1)
                return((*err = 1), doc);
            doc.textures.so = check_textures(*str_doc, &err_doc, "SO");
            if(err_doc == -1)
                return((*err = 1), doc);
            doc.textures.we = check_textures(*str_doc, &err_doc, "WE");
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
    print_doc(doc);
    if (err)
        return(0);
    return(1);
}
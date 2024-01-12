#include "../../cub3d.h"

int check_extension(char *document)
{
    if(ft_str_rev_n_cmp(document, ".cub", 4))
        return(printf("incorrect extension\n"), 0);
    return (1);
}

// int check_name(char *document)
// {

// }

// int check_extension(char *document)
// {
//     if(!check_name(document))
//         return(0);
//     return (1);
// }

char **create_document(char *extension)
{
    char    *line_document;
    char    *new_line;
    int     fd;

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
    printf("%s\n", line_document);
    return (NULL); 
}

int parser(int argc, char **argv)
{
    char    **document;
    if(argc != 2)
        return(printf("incorrect number of arguments"), 0);
    if (!check_extension(argv[1]))
        return(0);
    document = create_document(argv[1]);
    if(!document)
        return(0);
    // if (!check_elements(document))
    //     return(0);
    return(1);
}
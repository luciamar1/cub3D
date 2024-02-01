#include "../../cub3d.h"

char **read_document(char *extension)
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
        if (!line_document && new_line)
            return(free(new_line), NULL);
    }
    doc = ft_split(line_document, '\n');
    if(line_document)
        free(line_document);
    return (doc); 
}
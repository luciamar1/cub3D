#include "cub3d.h"

char **read_document(char *extension)
{
    char    *line_document;
    char    *new_line;
    int     fd;
    char    **doc;
    char    *aux[2];

    fd = ((line_document = NULL), open(extension, O_RDONLY));
	if (fd < 0)
		return (printf("the file can't be open\n"), NULL);
    while(1)
    {
        new_line = get_next_line(fd);
        if(!new_line)
            break;
        aux[1] = ((aux[0] = line_document), new_line);
        line_document = ft_strjoin_better(&line_document, &new_line);
        free(aux[0]);
        free(aux[1]);
        if (!line_document)
            return(free(new_line), NULL);
    }
    doc = ft_split(line_document, '\n');
    if(line_document)
        free(line_document);
    return (doc); 
 }
 
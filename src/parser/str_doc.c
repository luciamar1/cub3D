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
        if (!line_document && new_line)
            return(free(new_line), NULL);
    }
    doc = ft_split(line_document, '\n');
    if(line_document)
        free(line_document);
    return (doc); 
 }
// void    put_lines(char **doc_biarr, char **aux, char *new_line)
// {
//     while(*aux)
//     {
//         *doc_biarr = *aux;
//         aux ++;
//         doc_biarr ++;
//     }
//     *doc_biarr = new_line;
//     //doc_biarr ++;
//     //*doc_biarr = NULL;
// }


// char **read_document(char *extension)
// {
//     char    **doc_biarr;
//     char    *new_line;
//     int     fd;
//     int     lines;
//     char    **aux;
//     char    *str_aux;

//     lines = 1;
//     doc_biarr = ft_calloc(sizeof(char *), lines);
//     if(!doc_biarr)
//         return(NULL);
//     fd = (open(extension, O_RDONLY));
// 	if (fd < 0)
// 		return (printf("the file can't be open\n"), NULL);
//     while(1)
//     {
//         new_line = get_next_line(fd);
//         if(!new_line)
//             break;
//         lines ++;
//         aux = doc_biarr;
//         if(*new_line != '\n')
//         {
//             str_aux = new_line;
//             new_line = ft_strtrim(new_line, "\n");
//             free(str_aux);
//             doc_biarr = ft_calloc(sizeof(char *), lines);
//             if(!doc_biarr)
//             {
//                 free_biarr(aux);
//                 free(new_line);
//                 return(NULL);
//             }
//             put_lines(doc_biarr, aux, new_line);
//             free(aux);
//         }
//         else
//             free(new_line);
//     }
//     return (doc_biarr); 
// }
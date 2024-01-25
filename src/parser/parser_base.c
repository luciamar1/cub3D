#include "../../cub3d.h"

int check_extension(char *document)
{
    if(ft_str_rev_n_cmp(document, ".cub", 4))
        return(printf("incorrect extension\n"), 0);
    return (1);
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
    //print_biarr(strbi_doc);
    //printf("%s\n", *strbi_doc);
    doc = check_create_document(strbi_doc, &err);
    free_biarr(strbi_doc);
    if (err)
        return(free_biarr(doc.map), 0);
    //if(!check_map(doc.map))
     //   return(free_biarr(doc.map), 0);
    print_doc(doc);
    return(1);
}
#include "../../cub3d.h"

int check_extension(char *document)
{
    if(ft_str_rev_n_cmp(document, ".cub", 4))
        return(print_error("incorrect extension\n"), 0);
    return (1);
}


t_doc   parser(int argc, char **argv, int *err_parser)
{
    char    **strbi_doc;
    t_doc   doc;
    int     err;

    err = 0;
    ft_bzero(&doc, sizeof(t_doc));
    if(argc != 2)
        return((*err_parser = 1), print_error("incorrect number of arguments"), doc);
    if (!check_extension(argv[1]))
        return((*err_parser = 1), doc);
    strbi_doc = read_document(argv[1]);
    if(!strbi_doc)
        return((*err_parser = 1), doc);
    //print_biarr(strbi_doc);
    //print_error("%s\n", *strbi_doc);
    doc = check_create_document(strbi_doc, &err);
    if(strbi_doc)
        free_biarr(strbi_doc);
    if (err)
        return((*err_parser = 1), free_biarr(doc.map), doc);
    //if(!check_map(doc.map))
     //   return(free_biarr(doc.map), 0);
    print_doc(doc);
    return((*err_parser = 0), doc);
}

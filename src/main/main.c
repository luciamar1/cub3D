#include "../../cub3d.h"

int main(int argc, char **argv)
{
	int		err;
	t_doc	doc;

	err = 0;
	doc = parser(argc, argv, &err);
	if(err)
		return(1);
	return(0);
}

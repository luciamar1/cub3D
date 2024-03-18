#include "cub3d.h"

int main(int argc, char **argv)
{
	int		err;
	t_doc	doc;

	err = 0;
	doc = parser(argc, argv, &err);
	if (err)
		return (1);
	printf("mapa bueno\n\n");
	// doc.map.person.x = 3;
	// doc.map.person.y = 2;
	// doc.map.direction.x = -1;
	// doc.map.direction.y = 2;
	printf("\n\nmain\nperson %f %f\n", doc.map.person.x, doc.map.person.y);
    printf("orientation %f %f\n", doc.map.direction.x, doc.map.direction.y);
	printf("distance %f\n", calculate_distance(&(doc.map)));
	//free_biarr(doc.map);
	return(0);
}

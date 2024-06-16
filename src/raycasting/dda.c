#include "cub3d.h"

static int	isWall(t_float_vector collision, t_float_vector direction, char** bimap) {
	t_vector	toCheck;

	if (collision.x == (float) (int) collision.x)
	{
		if (direction.x > 0)
			toCheck.x = collision.x;
		else
			toCheck.x = collision.x - 1;
		toCheck.y = ceilf(collision.y - 1);
	}
	else
	{
		if (direction.y > 0)
			toCheck.y = collision.y;
		else
			toCheck.y = collision.y - 1;
		toCheck.x = ceilf(collision.x - 1);
	}
	return bimap[toCheck.x][toCheck.y] == '1';
}

static float	v_distance(t_float_vector v1, t_float_vector v2)
{
	t_float_vector	subs;
	float			prode;

	subs.x = v1.x - v2.x;
	subs.y = v1.y - v2.y;
	prode = powf(subs.x, 2) + powf(subs.y, 2);
	return sqrt(prode);
}

static t_float_vector	nextCheckBi(t_float_vector start, t_float_vector direction)
{
	t_float_vector	ret;
	t_float_vector	possible;

	if (direction.x < 0)
		possible.x = ceilf(start.x - 1);
	else
		possible.x = floorf(start.x + 1);
	if (direction.y < 0)
		possible.y = ceilf(start.y - 1);
	else
		possible.y = floorf(start.y + 1);
	if (fabs((possible.x - start.x) / direction.x) > fabs((possible.y - start.y) / direction.y))
	{
		ret.y = possible.y;
		ret.x = start.x + direction.x * (possible.y - start.y) / direction.y;
	}
	else
	{
		ret.x = possible.x;
		ret.y = start.y + direction.y * (possible.x - start.x) / direction.x;
	}
	return (ret);
}

static t_float_vector	nextCheck(t_float_vector start, t_float_vector direction)
{
	t_float_vector	ret;

	if (direction.x == 0) {
		ret.x = start.x;
		if (direction.y < 0)
			ret.y = ceilf(start.y - 1);
		else
			ret.y = floorf(start.y + 1);
	}
	else if (direction.y == 0) {
		ret.y = start.y;
		if (direction.x < 0)
			ret.x = ceilf(start.x - 1);
		else
			ret.x = floorf(start.x + 1);
	}
	else
		ret = nextCheckBi(start, direction);
	return (ret);
}

float	ray(t_map map, t_float_vector *collision, t_float_vector direction)
{
	int	found;

	collision->x = map.person.x;
	collision->y = map.person.y;
	found = 0;
	while (!found)
	{
		*collision = nextCheck(*collision, direction);
		found = isWall(*collision, direction, map.bimap);
	}
	return v_distance(map.person, *collision);
}

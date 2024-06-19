#include "cub3d.h"

// this is needed due lack of perfect precision in floats
static int	is_zero(float direction)
{
	return (direction < 0.0001 && direction > -0.0001);
}

static int	is_wall_mid(t_fvector collision, t_fvector direction, char **bimap)
{
	t_vector	to_check;

	if (is_zero(direction.x))
	{
		if (direction.y > 0)
			to_check.y = collision.y;
		else
			to_check.y = collision.y - 1;
		return ((bimap[(int) collision.x - 1][to_check.y] == '1') \
			|| (bimap[(int) collision.x][to_check.y] == '1'));
	}
	else
	{
		if (direction.x > 0)
			to_check.x = collision.x;
		else
			to_check.x = collision.x - 1;
		return ((bimap[to_check.x][(int) collision.y - 1] == '1') \
			|| (bimap[to_check.x][(int) collision.y] == '1'));
	}
}

int	is_wall(t_fvector collision, t_fvector direction, char **bimap)
{
	t_vector	to_check;

	if (collision.x == (int) collision.x && collision.y == (int) collision.y \
		&& (is_zero(direction.x) || is_zero(direction.y)))
		return (is_wall_mid(collision, direction, bimap));
	if (collision.x == (int) collision.x)
	{
		if (direction.x > 0)
			to_check.x = collision.x;
		else
			to_check.x = collision.x - 1;
		to_check.y = ceilf(collision.y - 1);
	}
	else
	{
		if (direction.y > 0)
			to_check.y = collision.y;
		else
			to_check.y = collision.y - 1;
		to_check.x = ceilf(collision.x - 1);
	}
	return (bimap[to_check.x][to_check.y] == '1');
}

static t_fvector	next_check_bi(t_fvector start, t_fvector direction)
{
	t_fvector	ret;
	t_fvector	possible;

	if (direction.x < 0)
		possible.x = ceilf(start.x - 1);
	else
		possible.x = floorf(start.x + 1);
	if (direction.y < 0)
		possible.y = ceilf(start.y - 1);
	else
		possible.y = floorf(start.y + 1);
	if (fabs((possible.x - start.x) / direction.x) \
		> fabs((possible.y - start.y) / direction.y))
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

t_fvector	next_check(t_fvector start, t_fvector direction)
{
	t_fvector	ret;

	if (direction.x == 0)
	{
		ret.x = start.x;
		if (direction.y < 0)
			ret.y = ceilf(start.y - 1);
		else
			ret.y = floorf(start.y + 1);
	}
	else if (direction.y == 0)
	{
		ret.y = start.y;
		if (direction.x < 0)
			ret.x = ceilf(start.x - 1);
		else
			ret.x = floorf(start.x + 1);
	}
	else
		ret = next_check_bi(start, direction);
	return (ret);
}

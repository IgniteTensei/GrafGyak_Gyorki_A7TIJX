#include "cuboid.h"
#include <math.h>
#include <stdbool.h>

void set_size(Cuboid* cuboid, double x, double y, double z)
{
	cuboid->x = x;
	cuboid->y = y;
	cuboid->z = z;
}

double calc_volume(const Cuboid* cuboid)
{
	double area = cuboid->x * cuboid->y * cuboid->z;
	return area;
}

double calc_surface(const Cuboid* cuboid)
{
	double surface = ((cuboid->x * cuboid->y) + (cuboid->z * cuboid->x) + (cuboid->y * cuboid->z)) * 2;
	return surface;
}

bool isSquare(const Cuboid* cuboid)
{
	if (cuboid->x == cuboid->y || cuboid->x == cuboid->z || cuboid->y == cuboid->z)
	{
		return true;
	}
	else	
	{
        return false;
    }
}

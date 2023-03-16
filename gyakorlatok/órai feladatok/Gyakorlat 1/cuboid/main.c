#include "cuboid.h"
#include <stdio.h>
#include <stdbool.h>

int main(int argc, char* argv[])
{
	Cuboid cuboid;
	double area;
	double surface;
	bool sq;
	
	set_size(&cuboid, 20, 20, 40);

	area = calc_volume(&cuboid);
	surface = calc_surface(&cuboid);
	sq = isSquare(&cuboid);

	printf("Cuboid X: %lf\n", cuboid.x);
	printf("Cuboid Y: %lf\n", cuboid.y);
	printf("Cuboid Z: %lf\n", cuboid.z);
	printf("Cuboid area: %lf\n", area);
	printf("Cuboid surface: %lf\n", surface);

	if(sq)
	{
		printf("The cuboid has a square!");
	}
	
	
	return 0;
}
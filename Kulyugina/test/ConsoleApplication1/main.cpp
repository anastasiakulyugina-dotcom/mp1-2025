#include "stdio.h"
#include "minmax.h"


int main()
{
	int x  = 10, y = 9, z = 8;
	student s;

	z = mymax(x, y);
	y = mymin(x, z);

	printf("%d %d\n", z, y);

}
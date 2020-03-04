#include <stdio.h>
void square_cube(int x, int *y, int *z);
void square_cube(int x, int *y, int *z)
{
	*y = x * x;
	*z = x * x * x;
}
int main()
{
	int num, sqr, cube;
	
	printf ("Enter the number\n");
	scanf ("%d",&num);
	square_cube(num, &sqr, &cube);
	printf ("Number= %d\t Square= %d\t Cube= %d\t\n",num, sqr, cube);

	return 0;
}


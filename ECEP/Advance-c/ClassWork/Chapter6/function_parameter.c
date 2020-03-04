#include <stdio.h>

int prod(int a, int b)
{
	return a * b;
}

int add(int a, int (*fp)(int, int))
{
	return a +(*fp)(10,20);
}

int main()
{
	//Calling the function through function pointer
	printf("Res: %d\n", add(3, prod));

	return 0;
}

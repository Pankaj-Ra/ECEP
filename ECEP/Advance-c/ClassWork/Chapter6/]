				/* Passing the function as a parameter to the other function */ 
#include <stdio.h>

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int prod(int a, int b)
{
	return a * b;
}

int div(int a, int b)
{
	return a / b;
}

int main()
{
	//Defining the array of function pointers
	int (*fp[4])(int, int) = {div, prod, add, sub};

	int i;
	for (i = 0; i < 4; i++)
	{
		printf("Res: %d\n", (*fp[i])(20, 10));
	}

	return 0;
}


#include <stdio.h>

int factorial(int num)
{
	if (num == 0)					   //terminating condition , when num reaches 0 , it returns 1.
	{
		return 1;
	}
	return (num * factorial(num - 1)); //recursive function 
}
int main()
{
	int num, result;

	printf ("Enter the number\n");
	scanf ("%d",&num);
	result = factorial(num);
	printf ("factorial of %d! is = %d",num, result);
	printf ("\n");

	return 0;
}


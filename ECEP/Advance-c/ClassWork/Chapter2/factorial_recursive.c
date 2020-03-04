#include<stdio.h>
int factorial(int num);
int factorial(int num)
{
	if (num == 0)
	{
		return 1;
	}
	return (num * factorial(num - 1));
}
main()
{
	int num, result;
	printf ("Enter the number\n");
	scanf ("%d",&num);
	result = factorial(num);
	printf ("factorial of %d! is = %d",num, result);
	printf ("\n");
}


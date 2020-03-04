#include<stdio.h>
int factorial(int num);
int factorial(int num)
{
	int i, result;
	for(i = num;i > 1;i--)
	{
		result = num * (i - 1);
		num = result;
	}
	return (result);
}
main()
{
	int num, result;
	printf ("Enter the number\n");
	scanf ("%d",&num);
	result = factorial(num);
	printf ("factorial of %d is = %d\n",num, result);
}


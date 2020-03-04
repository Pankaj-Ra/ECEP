#include <stdio.h>
int num, a = 0, b = 1, sum = 0;
//int fibo(int i, int a, int b);
//int fibo(int i, int a, int b)
int fibonacci(int i);
int fibonacci(int i)
{
	if (i == num)
	{
		return (a);
	}
	sum = a + b;
	printf ("%d\t",a);
	a = b;
	b = sum;
	fibonacci(i + 1);
//  fibo(i + 1, a, b);
}
int main()
{
	int i = 0;

	printf ("Enter the limit\n");
	scanf ("%d",&num);
	printf ("Fibonacci series up to %d is :\n",num);
	fibonacci(i);
//  fibo(i, a, b);
	printf ("\n");

	return 0;
}


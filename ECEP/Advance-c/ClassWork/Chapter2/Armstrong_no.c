#include<stdio.h>
int armstrong(int num);
int armstrong(int num)
{
	int i, sum, new, rem;
	while (num > 0)
	{
	rem = num % 10;
	sum = sum + rem * rem * rem;
	new = num/10;
	num = new;
	}
	return (sum);
}
main()
{
	int num, new;
	printf ("Enter the number\n");
	scanf ("%d",&num);
	new = armstrong(num);
	printf ("%d\n",new);
	if (num == new)
	{
		printf ("Armstrong number\n");
	}
	else
		printf ("Not an Armstrong number\n");
}



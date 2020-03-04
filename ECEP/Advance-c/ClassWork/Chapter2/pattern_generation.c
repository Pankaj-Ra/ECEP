#include<stdio.h>
int num, i;
int pattern(int num);
int pattern(int num)
{
	if (num >= 1)
	{
		for (i = num;i >=1; i--)
		{
		printf ("%d\t",i);
		}
	}
	else
		return;
	printf ("\n");
	pattern(num - 1);
}
main()
{
	printf ("Enter the number\n");
	scanf ("%d",&num);
	pattern(num);
	printf ("\n");
}



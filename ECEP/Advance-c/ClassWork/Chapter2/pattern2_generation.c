#include<stdio.h>
int i, count = 1, num;
int pattern(int count);
int pattern(int count)
{
	if (count <= num)
	{
		for (i = 1;i <= count;i++)
		{
			printf ("%d\t",i);
		}
	}
	else
		return;
	printf ("\n");
	pattern(count + 1);
}
main()
{
	printf ("Enter the number\n");
	scanf ("%d",&num);
	pattern(count);
	printf ("\n");
}
	

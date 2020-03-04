#include<stdio.h>
int main()
{
	int i, array[5];
	printf ("Enter 5 values\n");
	for (i = 0; i < 5; i++)
	{
	scanf ("%d",&array[i]);
	}
	printf ("The 5 values are : \n");
	for (i = 0; i < 5; i++)
	{
		printf ("%d\n",array[i]);
	}
}


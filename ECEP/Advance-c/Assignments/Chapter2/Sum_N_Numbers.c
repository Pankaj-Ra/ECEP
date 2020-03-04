#include<stdio.h>
main()
{
	int  i, N, ADD = 0;
	printf ("ENTER the Range\n");
	scanf ("%d",&N);
	int array[N];
	for (i = 0;i < N;i++)
	{
		scanf ("%d",&array[i]);
	}
	for (i = 0;i < N;i++)
	{
       ADD = ADD + array[i];
	}
	printf ("SUM = %d\n",ADD);
}


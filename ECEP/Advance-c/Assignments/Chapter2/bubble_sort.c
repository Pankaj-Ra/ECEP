#include<stdio.h>
main()
{
	int i, j, N, store;
	printf ("Enter the limit\n");
	scanf ("%d",&N);
	int array[N];
	printf ("Enter the Numbers\n");
	for (i = 0;i < N;i++)
	{
		scanf ("%d",&array[i]);
	}
	printf ("Bubble Sorting:\n");
	for (i = N-1;i >=0;i--)
	{
		for (j =  0;j < i;j++)
		{
			if (array[j] > array[j+1])
			{
				store = array[j];
				array[j] = array[j+1];
				array[j+1] = store;
			}
		}
	}
	for (i = 0;i < N;i++)
	{
		printf ("%d\t",array[i]);
	}
	printf ("\n");
}



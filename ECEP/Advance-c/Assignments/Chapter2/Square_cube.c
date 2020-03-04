#include<stdio.h>
main()
{
	int i, N, OUT = 0, temp;
	printf ("How many Numbers?\n");
	scanf ("%d",&N);
	int array[N];
	printf ("Enter the %d Numbers :\n",N);
	for (i = 0;i < N;i++)
	{
		scanf ("%d",&array[i]);
	}
	temp = OUT;
	for (i = 0;i < N;i++)
	{
	OUT = array[i] * array[i];
	printf ("Squate Root of:%d = %d\t",array[i], OUT);
	OUT = temp;
	OUT = array[i] * array[i] * array[i];
	printf ("Cube Root of:%d = %d\n",array [i], OUT);
	}
}



#include<stdio.h>
main()
{
	int N,SUM,i=1;
	printf ("Enter the number\n");
	scanf ("%d",&N);
	while (i<N+1)
	{
		SUM=i*(i+1)/2;
		i++;
	}
	printf ("Sum of Numbers: %d\t\n",SUM);
}


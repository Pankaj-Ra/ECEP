#include<stdio.h>
main()
{
	int N,i,j,MUL;
	printf ("Enter the Number\n");
	scanf ("%d",&N);
	for (i=1;i<=N;i++)
	{
		for (j=1;j<=10;j++)
		{
			MUL=i*j;
			printf ("%d\t",MUL);
		}
		printf ("\n");
	}
}


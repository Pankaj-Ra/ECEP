#include<stdio.h>
main()
{
	int N, i, j, k;
	printf ("ENTER the Size\n");
	scanf ("%d",&N);
	if (N%2 == 1)
	{
		N = N+1;
	}
	for (k=N;k>0;k--)
	{
	for (i=0;i<=k;i++)                      //this for loop is used to increment rows up to N
	{
		for (j=0;j<=k;j++)                  //this for loop is use to increment column horizontaly in same line
		{
		if ((i+k/2 == j) || (-i+k/2 == j) || (j+k/2 == i) || (-j+k/2 + k == i))       //if value of row is equal to column OR value of row is equal to SIZE - Column
//			if ((i+j)%2 == 0) 
			{
				printf (" *");
			}
			else
			{
				printf ("  ");
			}
		}
		printf ("\n");
	}
	}
	printf ("\n");
}


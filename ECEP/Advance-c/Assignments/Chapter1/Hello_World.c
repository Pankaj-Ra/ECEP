#include <stdio.h>
int main()
{
	int N, i, j;

	printf ("ENTER the Size\n");
	scanf ("%d",&N);
	for (i = 0; i <= N; i++)						//this for loop is used to increment rows up to N
	{
		for (j = 0; j <= N; j++)					//this for loop is use to increment column horizontaly in same line
		{
			if (i == j || i == (N-j))		//if value of row is equal to column OR value of row is equal to SIZE - Column
			{
				printf ("Hello World");
			}
			else 
			{
				printf ("  ");
			}
		}
		printf ("\n");
	}
	printf ("\n");

	return 0;
}


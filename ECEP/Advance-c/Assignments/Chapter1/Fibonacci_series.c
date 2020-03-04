#include <stdio.h>
int main()
{
	int N, i, NUM1=0, NUM2=1, GREAT=0;

	printf ("Enter the Number\n");
	scanf ("%d",&N);
	printf ("Fibonacci Series up to %d is\t",N);
	for (i = 0; i <= N + 1; i++)
	{
		if (NUM1 <= N)
		{
		GREAT = NUM1 + NUM2;		   //Sum (next value) is equal to additon of last 2 numbers
		printf ("%d\t",NUM1);		   //if we print NUM2, it includes first two values 0, 1. where GREAT starts from 1
		NUM1 = NUM2;				   
		NUM2 = GREAT;
		}
	}
	printf ("\n");

	return 0;
}


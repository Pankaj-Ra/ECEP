#include<stdio.h>
#include<math.h>
main()
{
	int N, i, COUNT, REMENDER;
RESULT: printf ("ENter the Number\n");
	scanf ("%d",&N);
	COUNT=sqrt(N);
	if (N < 2)
	{
		printf ("Please enter a valid input");
		goto RESULT;
	}
	for (i=2;i<=COUNT;i++)
	{
	REMENDER = (N % i);
	if (REMENDER == 0)
	{
		printf ("Not a Prime number");
		break;
	}
	}
	if (REMENDER !=0)
	{
		printf ("Prime Number");
	}
	printf ("\n");
}





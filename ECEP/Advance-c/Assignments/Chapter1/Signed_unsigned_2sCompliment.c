#include <stdio.h>
int main()
{
	int N, BITS, MASK, i;

	printf ("Enter the Number\n");
	scanf ("%d",&N);
	printf ("Binary form of %d is :\n",N);
	BITS = sizeof(int) * 8;
	for (i = BITS - 1; i >= 0; i--)			         //for loop is used to print binary up to the size of the int.
	{
		MASK = 1 << i;
		if (MASK & N)
		{
			printf ("1");
		}
		else
		{
			printf ("0");
		}
	}
	printf ("\n2's Compliment of %d is :\n",N);
	for (i = BITS - 1; i >= 0; i--)
	{
		MASK = 1 << i;
		if (MASK & (~N + 1))                         //first we take 2's comliment of number and then print its binary.
		{
			printf ("1");
		}
		else
		{
			printf ("0");
		}
	}
	printf ("\n");

	return 0;
}






#include <stdio.h>
int main()
{
	int NUM, CHECK, MASK = 1;

	printf ("Enter the Value\n");
	scanf ("%d",&NUM);
	CHECK = NUM & MASK;					// if last bit of number is 0 than its a even num and if its 1 than odd.
	if (CHECK == 0)
	{
		printf ("EVEN");
	}
	else
	{
		printf ("ODD");
	}
	printf ("\n");

	return 0;
}

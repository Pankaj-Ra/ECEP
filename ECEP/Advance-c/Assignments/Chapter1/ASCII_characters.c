#include <stdio.h>

int main()
{
	int i;

	char OUT;
	for (i = 33; i <= 127; i++)
	{
		OUT = i;
		printf ("ASCII value: = %d \t%c\n", i, OUT);
	}
	printf ("\n");
	
	return 0;
}


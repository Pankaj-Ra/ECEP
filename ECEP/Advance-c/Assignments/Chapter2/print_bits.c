#include<stdio.h>
int print_bits(int num);
int print_bits(int num)
{
	unsigned int mask;
	for (mask = 1 << (sizeof(int)*8 - 1); mask; mask >>= 1)
	{
		(mask & num) ? printf("1") : printf("0");
	}
	return;
}
int main()
{
	int num;
	printf ("Enter the Number\n");
	scanf ("%d",&num);
	printf ("Binary for %d is = \n",num);
	print_bits(num);
	printf ("\n");

	return 0;
}



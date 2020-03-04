#include<stdio.h>
main()
{
	unsigned int out, mask, bits;
	int i;
	out = (~0 >> 3);
	bits = sizeof(int) * 8;
	for (i = (bits - 1);i >= 0;i--)
	{
		mask = 1 << i;
		if (out & mask)
		{
			printf ("1");
		}
		else
		{
			printf ("0");
		}
	}
}




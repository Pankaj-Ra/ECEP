#include <stdio.h>

#define TOGGLE(num) (num >> 4 | num << 4)

void print_bits(unsigned char num)
{
	unsigned mask;

	for (mask = 1 << (sizeof(char)*8 - 1); mask; mask >>= 1)
	{
		(mask & num) ? printf("1") : printf("0");
	}
}

int main()
{
	unsigned char num;
	unsigned char new, mask;
	printf("Enter the number\n");
	scanf("%x", &num);

	printf("Binary of given number %x:\n",num);

	print_bits(num);

	new = TOGGLE(num);

	printf("\nNew Value after swapping nibbles of num %x :\n", new);

	print_bits(new);
	return 0;
}



#include <stdio.h>

#define TOGGLE(num, pos) ((1 << (pos - 1))^num)

void print_bits(int num)
{
	unsigned mask;

	for (mask = 1 << (sizeof(int)*8 - 1); mask; mask >>= 1)
	{
		(mask & num) ? printf("1") : printf("0");
	}
}

int main()
{
	int num, pos;
	unsigned int new, mask;
	printf("Enter the number\n");
	scanf("%d", &num);
	printf("Enter bit position to toggle\n");
	scanf("%d", &pos);

	printf("Binary of given number :\n", pos, num);

	print_bits(num);

	new = TOGGLE(num , pos);

	printf("\nNew Value after toggle %d bit of num %d :\n", pos, num);

	print_bits(new);
	return 0;
}




#include <stdio.h>
#define BIG_ENDIAN 1
#define LITTLE_ENDIAN 0

typedef unsigned int u_int32_t;
typedef unsigned char u_char8_t;

typedef union
{
	u_int32_t word;
	u_char8_t byte[4];
}data_t;

int check_endianess(void)
{
	int val = 0xdd;
	data_t x;
	x.word = 0xaabbccdd;

	printf("byte:  %x  value: %x\n", x.byte[0], val);

	if ((x.byte[0] == (u_char8_t)0xdd) && (&x.byte[0] < &x.byte[1]))
	{
		return LITTLE_ENDIAN;
	}
	else
	{
		return BIG_ENDIAN;
	}

}

int main()
{
	if (check_endianess() == LITTLE_ENDIAN)
	{
		printf("\nLITTLE ENDIANESS\n");
	}
	else
	{
		printf("\nBIG\n");
	}
}


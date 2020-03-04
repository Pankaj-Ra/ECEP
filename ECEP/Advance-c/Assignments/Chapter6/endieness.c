							/* Check Endianess of Processor*/
#include <stdio.h>
#define BIG_ENDIAN 1
#define LITTLE_ENDIAN 0

//Typedefine datatype
typedef unsigned int u_int32_t;
typedef unsigned char u_char8_t;

//Typedefine Union structure
typedef union
{
	u_int32_t word;
	u_char8_t byte[4];
}data_t;

//Function to find endianess of processor
int check_endianess(void)
{
	int val = 0xdd;
	data_t x;
	x.word = 0xaabbccdd;

	printf("byte:  %x  value: %x\n", x.byte[0], val);

        //value stored at location x.byte[0] is equal to LSB byte + the address of that location occur before the next
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
	//checking condition and print result
	if (check_endianess() == LITTLE_ENDIAN)
	{
		printf("\nLITTLE ENDIANESS\n");
	}
	else
	{
		printf("\nBIG\n");
	}
}


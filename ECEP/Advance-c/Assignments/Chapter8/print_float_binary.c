							/* Read Float and find out (sign-bit, exponent, mantissa) and print intiger part */
#include <stdio.h>
#include <stdlib.h>

//Define the bit-field structure
typedef struct bit_field
{
	unsigned mantissa: 23;
	unsigned exponent: 8;
	unsigned sign    : 1;
}bit_f;

void print_bits(unsigned int num, int n);
void find_intiger();

int main()
{
	float f;

	//Read the float number
	printf("Enter the float number\n");
	scanf("%f", &f);

	bit_f *p = (bit_f *)(&f);

	//Print binayform of the float number
	printf("\nSign-Bit   \t:  ");
	print_bits(p->sign, 1);
	printf("Exponent     \t:  ");
	print_bits(p->exponent, 8);
	printf("Mantissa     \t:  ");
	print_bits(p->mantissa, 23);

	//Calling function to find intiger part
    find_intiger(p);

    printf("Integer Binary  :  ");
    print_bits(p->mantissa, 23);
}

//Function to find the demoted intiger value of float
void find_intiger(bit_f *p)
{
	p->exponent -= 127;
	p->mantissa >>= 1;
	p->mantissa |= (1 << 22);
	p->mantissa >>= (22 - p->exponent);
	printf("Integer value   :  %d\n", p->mantissa);
}

//function to print in binary
void print_bits(unsigned int num, int n)
{
	unsigned mask;

	for (mask = 1 << (n - 1); mask; mask >>=1)
	{
		num & mask? printf("1"): printf("0");
	}
	printf("\n");
}



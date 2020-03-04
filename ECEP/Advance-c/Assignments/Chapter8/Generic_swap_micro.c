						  	/* Define Macro to swap arguments of given type*/
#include <stdio.h>

//Macro use to swap variables
#define GENERIC_SWAP(type, a, b) {type temp = a;\
	                              a = b;\
	                              b = temp;}

int main()
{
	//Declare variables and datatypes
	int a, b;
	float c, d;

	//Getting input from the user for intiger datatype
	printf("Enter the first intiger value a\n");
	scanf("%d", &a);
	printf("Enter the second intiger value b\n");
	scanf("%d", &b);

	//Printing values before swap
	printf("Before swap:\na: %d\tb: %d\n", a, b);

	//Passing values and type to macro
	GENERIC_SWAP(int, a, b);

	//printing values after swap
	printf("After swap:\na: %d\tb: %d\n", a, b);

	//Getting input from user for float datatype
	printf("Enter the first float value c\n");
	scanf("%f", &c);
	printf("Enter the second float value d\n");
	scanf("%f", &d);

	//printing values before swap
	printf("Before swap: \nc: %f\td: %f\n", c, d);

	//passing values and type to macro
	GENERIC_SWAP(float, c, d);

	//printing values after swap
	printf("After swap: \nc: %f\td: %f\n", c, d);

	return 0;
}

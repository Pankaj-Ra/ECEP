                            /* Print bits of float & double. check IEEE format */
#include <stdio.h>

//Function used to print in binary format taking intiger pointer and size of data type as input parameters
void print_binary(int *ptr, int size)
{
	//Declaring variables 
	int i, mask, count = sizeof(int) * 8;

	//this for loop run if size of input datatype is bigger than int
	if (size > sizeof(int))
	{
		for (i = (count - 1); i >= 0; i--)
		{
			mask = 1 << i;
			if (mask & *(ptr + 1))
			{
				printf("1");
			}
			else
			{
				printf("0");
			}
		}
	}
	
	//Print in binary form
	for (i = (count - 1); i >= 0; i--)
	{
		mask = 1 << i;
		if (mask & *ptr)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
	}
	printf("\n");
}

int main()
{
	//Declare input variables and datatypes
	float num1;
	double num2;

	printf("Enter the float value\n");
	scanf("%f",&num1);
	printf("Enter the Double value\n");
	scanf("%lf",&num2);

	printf("Printing float value %f in binary format:\n", num1);

	//Calling function and type casting float datatype into int
	print_binary(((int *)&num1), sizeof(float));

	printf("Printing double value %lf in binary format: \n", num2);

	//calling function and type casting double datatype into int
	print_binary(((int *)&num2), sizeof(double));

	return 0;
}





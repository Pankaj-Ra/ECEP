#include <stdio.h>

int main()
{
	//Declaire the array and pointer types
	int a[4] = {10,20,30,40}, *ptr = a, i = 0;

	//To print contents and address of array
    for (i = 0; i < 4; i++)
	{
		printf("Value of array at location %p is: %d\n",ptr, *ptr);
		ptr++;
	}

	return 0;

}

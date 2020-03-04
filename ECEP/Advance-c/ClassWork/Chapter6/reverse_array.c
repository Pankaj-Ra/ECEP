#include <stdio.h>

int main()
{
	//Declare array and pointer type
	double a[4] = {10.1,20.2,30.3,40.4}, *ptr = a, temp, temp1;
	int size, i ;

	size = sizeof(a)/sizeof(double);

	//Print the array
	printf("Present array: = ");
	for (i = 0; i < size; i++)
	{
		printf("%lf\t",a[i]);
	}
	//Reverse elements of array
	i -= 1;
	while (i > 0)
	{
		temp = *ptr;
		ptr += i;
        temp1 = *ptr;
        *ptr = temp;
        ptr -= i;
        *ptr = temp1;
		ptr++;
		i--;
		i--;
	}

	//print the array
	printf("\nReverse array: = ");
	for (i = 0; i < size; i++)
	{
		printf("%lf\t",a[i]);
	}

	return 0;
	
}

#include <stdio.h>
#include <stdlib.h>
#define size 4

int main()
{
	//To Clear the output screen, it is system call.
	system("clear");

	//Declare array of pointer of size = 4
//	int *p[size];

	//Dynamically allocate the memory
    int **p = malloc(4 * sizeof(int *));

	//Printing the address + value present in that address
	int i;
	for (i = 0; i < size; i++)
	{
		printf("The value @ address %p: %p\n", (p + i), *(p + i));
	}
	printf("\n");

	//Malocing the memory for the rows
	for (i = 0; i < size; i++)
	{
		p[i] = malloc(4 * sizeof(int));
		printf("The value @address %p: %p\n", (p + i), *(p + i));
	}
	printf("\n");

	//Populating the 0th 1D array
	for (i = 0; i < size; i++)
	{
		*(p[0] + i) = 10 + (i * 10);
		printf("The value @address %p: %d\n", p[0] + i, *(p[0] + i));
	}
	printf("\n");

	//Populating the 1th 1D array
	for (i = 0; i < size; i++)
	{
		*(p[1] + i) = 10 + (i + 1);
		printf("The value @address %p: %d\n", p[1] + i, *(p[1] + i));
	}
	
	return 0;
	
}



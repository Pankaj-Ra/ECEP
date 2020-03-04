#include <stdio.h>
#define ROW 3
#define COL 3

int main()
{

	//Declare 2D array + Init
	int a[ROW][COL] = {1,2,3,4,5,6,7,8,9};

	int i, j;

	printf("printing using pointer notation\n");
	//Print the 2D array with pointer notation
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
		//	printf("a[%d][%d]: %d\t", i, j, *(*(a+i) + j));
		//	printf("a[%d][%d]: %d\t", i, j, *(a[i] + j));
			printf("a[%d][%d]: %d\t", i, j, (*(a+i))[j]);
		}
		printf("\n");
	}

	printf("printing using pointer variable\n");
	//Print the 2D array with pointer varaible
	
	//Declare the pointer to an array + Init
	int (*ap)[COL] = a;

	for (i = 0; i < ROW; i++, ap++)
	{
		//Declare a normal pointer + INit
		int *p = (int*)ap;
		for (j = 0; j < COL; j++, p++)
		{
			printf("a[%d][%d]: %d\t", i, j, *p);
		}
		printf("\n");
	}

	//Re-Init pointer to an array, since ap is pointing to the end of the second array
	ap = a;
	printf("Printing using pointer to an array variable\n");

	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			printf("a[%d][%d]: %d\t", i, j, ap[i][j]);
		}
		printf("\n");
	}

	return 0;
}

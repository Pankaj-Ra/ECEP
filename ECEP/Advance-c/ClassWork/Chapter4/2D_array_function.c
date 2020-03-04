#include <stdio.h>
#define ROW 3
#define COL 3

//Function to print the 2D array
void print_array(int (*ap)[COL]);
void print_array(int (*ap)[COL])
{
	int i, j;
	printf("Printing in function\n");

	for(i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			printf("a[%d][%d]: %d\t", i, j, ap[i][j]);
		}
		printf("\n");
	}
}

int main()
{

	//Declare 2D array + Init
	int a[ROW][COL] = {1,2,3,4,5,6,7,8,9};

	print_array(a);

	return 0;

}


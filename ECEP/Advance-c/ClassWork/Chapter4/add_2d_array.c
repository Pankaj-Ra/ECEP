#include <stdio.h>
#define ROW 3
#define COL 3

int (*add_2Darray(int (*p)[COL], int (*q)[COL]))[COL]
{
	static int a[ROW][COL];
	int  i, j;

	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			a[i][j] = p[i][j] + q[i][j];
		}
	}

	return a;
}

int main()
{
	int array1[ROW][COL] = {1,2,3,4,5,6,7,8,9}, array2[ROW][COL] = {9,8,7,6,5,4,3,2,1}, (*pa)[COL];
	int i , j;

	printf("Matrix 1:\n");
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			printf("a[%d][%d]: %d\t",i, j, array1[i][j]);
		}
		printf("\n");
	}

	printf("Matrix 2:\n");
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			printf("b[%d][%d]: %d\t",i, j, array2[i][j]);
		}
		printf("\n");
	}

	pa = add_2Darray(array1, array2);

	printf("Resultant matrix after adding two 2D matrix is:\n");
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			printf("c[%d][%d]: %d\t",i, j, pa[i][j]);
		}
		printf("\n");
	}

	return 0;
}









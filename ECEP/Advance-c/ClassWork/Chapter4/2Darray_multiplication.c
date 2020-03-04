#include <stdio.h>
#define ROW 3
#define COL 3

int (*multipling_2Darray(int (*a)[COL], int (*b)[COL]))[COL]
{
	int i, j ,k; 
	static int m[ROW][COL];

	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			for (k = 0; k < COL; k++)
			{
				m[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	return m;
}

int main()
{

	int array1[ROW][COL] = {1,1,1,1,1,1,1,1,1};
	int array2[ROW][COL] = {1,1,1,1,1,1,1,1,1};
	int i, j, (*result)[COL];

	result = multipling_2Darray(array1, array2);
    printf("Resultant matrix after multiplying:\n");
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			printf("r[%d][%d]: %d\t", i, j, result[i][j]);
		}
		printf("\n");
	}
	
	return 0;

}


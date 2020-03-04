#include <stdio.h>

int main()
{
	int array[50][50], row, col;
	int size, min, max;

	printf("Enter the size of 2D array\n");
	scanf("%d",&size);
	printf("Enter the values\n");
	for ( row = 0; row < size; row++)
	{
		for ( col = 0; col < size; col++)
		{
			scanf("%d",&array[row][col]);
		}
	}

	for (row = 0; row < size; row++)
	{
		max = array[row][0];
		for (col = 1; col < size; col++)
		{
			if (max < array[row][col])
			{
				max = array[row][col];
			}
		}
		printf("Max value in row:%d  = %d\n", row, max);
		if (row == 0)
		{
			min = max;
		}
		if (min > max)
		{
			min = max;
		}
	}

	printf("Minimum value among max values is: = %d\n", min);

	return 0;
}



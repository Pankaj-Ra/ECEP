				 /* Generate magic Square for ODD n*n */
#include <stdio.h>
#define size 7

//Function use to create magic square
int (*magic_square())[size]
{
	//Initializing ROW and COL and Declaring static 2D array
	int ROW = 0, COL = size/2, k;
	static int magic[size][size];

	//for loop use to populate magic square up to  size x size of square
	for (k = 1; k <= size*size; k++)
	{
		//Row is decrimented by 1 and col is incrimented by one and value of k is stored
		magic[ROW][COL] = k;
		ROW -= 1;
		COL += 1;
		if ((ROW < 0) && (COL == size))
		{
			ROW += 2;
			COL -= 1;
			continue;
		}
		if (ROW < 0)
		{
			ROW = size - 1 ;
		}
		if (COL == size)
		{
			COL = 0;
		}
		if (magic[ROW][COL] > 0)
		{
			ROW += 2;
			COL -= 1;
			continue;
		}
	}
	return magic;
}

int main()
{
	//declare variables
	int ROW, COL, SIZE;

	printf("Enter the Size of Magic Square only odd intigers > 2\n");
	scanf("%d",&SIZE);

	//calling function and getting value using pointer to an array
	int (*magicP)[SIZE] = magic_square();

	printf("Magic Square of size %dx%d is:\n", SIZE, SIZE);

	for (ROW = 0; ROW < SIZE; ROW++)
	{
		for (COL = 0; COL < SIZE; COL++)
		{
			printf("\t%d", magicP[ROW][COL]);
		}
		printf("\n\n\n");
	}

	return 0;
}

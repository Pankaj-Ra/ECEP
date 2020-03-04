/***********************************************************************************************************************
 *Title  : Reading 'n' fragments, finding the average of all the elements & sorting the fragments according to the avg
 *Auther : Pankaj
 *Date   : 18 / 08 / 2015
 *Description:.....
 **********************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

void allocate_memory(float ***p, int n, int *size)
{
	//Allocate the memory for storing the base addres of all the rows
	*p = malloc(n * sizeof(float *));
	int i, s;
	for (i = 0; i < n; i++)
	{
		//Read the row size from the user + store the size in array
		printf("Enter %d row size\n", i);
		scanf("%d", (size + i));

		s = *(size + i);
		//Allocate row size memory + store the base address in particular location
		(*p)[i] = malloc((s + 1) * sizeof(float));
	}
}

void populate_rows(float ***p, int n, int *size)
{
	int i, j;

	//populating all memory fragments
	for (i = 0; i < n; i++)
	{
		//Read the vale from the user + store the value in array
		printf("Enter %d elements for %d row\n", *(size + i), i);
		for (j = 0; j < *(size + i); j++)
		{
			scanf("%f", (*p)[i] + j);
		}
	}
}

void average_rows(float ***p, int n, int *size)
{
	int i, j;
	float sum, avg;

	//calculating average of all elements of each array and store in corresponding last mem location
	for (i = 0; i < n; i++)
	{
		sum = 0;
		for (j = 0; j < size[i]; j++)
		{
			sum += (*p)[i][j];
		}
		avg = sum / size[i];
		(*p)[i][j] = avg;
	}
}

void sorting_rows(float ***p, int n, int *size)
{
	int i, j, temp;
	float *sort;

	//Sorting all rows by swapping their addresses according to avg
	for (j = (n - 1); j >= 0; j--)
	{
		for (i = 0; i < j; i++)
		{
			//comparing avg of 1st row with avg of 2nd row 
			if (*((*p)[i] + size[i]) > *((*p)[i + 1] + size[i + 1]))
			{
				//Swapping address of rows + swapping row size 
				sort = (*p)[i];
				(*p)[i] = (*p)[i + 1];
				(*p)[i + 1] = sort;
				temp = size[i];
				size[i] = size[i + 1];
				size[i + 1] = temp;
			}
		}
	}
}

int main()
{
	//Clear memory
	system("clear");

	//Declare a pointer to pointer float variable
	float **p;
	int n;

	//Read number of fragments
	printf("Enter number of fragments\n");
	scanf("%d", &n);

	//Allocate memory to store all the sizes of all the fragments
	int *size = malloc(n * sizeof(int));

	//Function call
	allocate_memory(&p, n, size);

	//To allocate size
	int i, j;
	for (i = 0; i < n; i++)
	{
		printf("The size of %d row: %d\n", i, *(size + i));
	}

	//Function call to populate the rows
	populate_rows(&p, n, size);

	printf("\n[All the rows before sorting]:\n\n");
	for (i = 0; i < n; i++)
	{
		printf("The elements of %d row are:\n", i);
		for (j = 0; j <= *(size + i); j++)
		{
			printf("%f\t", *(p[i] + j));
		}
		printf("\n");
	}

	//Function to find average and store in last element
	average_rows(&p, n, size);

	printf("\n[Average of all rows]:\n\n");
	for (i = 0; i < n; i++)
	{
		printf("The average of %d row is:\t", i);
		printf("%f\n", *(p[i] + size[i]));
		printf("\n");
	}

	//Function to sort rows according to avg using bubble sort
	sorting_rows(&p, n, size);

	printf("\n[Sorted rows according to Average]:\n\n");
	for (i = 0; i < n; i++)
	{
		printf("The average of %d row is:\t", i);
		printf("%f\n", *(p[i] + size[i]));
		printf("\n");
	}

	//Printing final output after sorting rows according to avg
	printf("\n[All the rows after sorting]:\n\n");
	for (i = 0; i < n; i++)
	{
		printf("The elements of %d row are:\n", i);
		for (j = 0; j <= *(size + i); j++)
		{
			printf("%f\t", *(p[i] + j));
		}
		printf("\n");
	}

	return 0;
}





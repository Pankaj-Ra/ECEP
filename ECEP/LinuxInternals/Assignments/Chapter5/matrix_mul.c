#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

struct matrix
{

	int mat1[100][100];
	int mat2[100][100];
	int res[100][100];
	int ROW1;
	int ROW2; 
	int COL1; 
	int COL2;
	int temp_row;
};

pthread_mutex_t lock;

void* max_function(void *arg)
{
	struct matrix *point = arg;

	int count;
	static int i, num = 1;
	static int m = 0;
	int j, k;
	i = m;
	point->temp_row = m++ ;

	for (j = 0; j < point->COL2; j++)
	{
		point->res[i][j] = 0;
		for (k = 0; k < point->COL1; k++)
		{
			pthread_mutex_lock(&lock);

			point->res[point->temp_row][j] += point->mat1[point->temp_row][k] * point->mat2[k][j];

			pthread_mutex_unlock(&lock);
		}
	}
}

int main()
{
	struct matrix key;
	pthread_t *threadID;

	int i, j;

	printf("Enter rows of matrix1: ");
	scanf("%d", &key.ROW1);
	printf("Enter columns of matrix1: ");
	scanf("%d", &key.COL1);
	printf("Enter rows of matrix2: ");
	scanf("%d", &key.ROW2);
	printf("Enter columns of matrix2: ");
	scanf("%d", &key.COL2);

	if (key.ROW2 != key.COL1)
	{
		printf("Matrix multipliction is not possible ROW2 != COL1 \n");
		return -1;
	}

	threadID = malloc(sizeof(pthread_t) * key.ROW1);

	printf("Enter the  %dx%d matrix 1 \n", key.ROW1, key.COL1);


	for (i = 0; i < key.ROW1; i++)
	{
		for (j = 0; j < key.COL1; j++)
		{
			scanf("%d", &key.mat1[i][j]);
		}
	}

	printf("Enter the %dx%d matrix 2 \n", key.ROW2, key.COL2);
	for (i = 0; i < key.ROW2; i++)
	{
		for (j = 0; j < key.COL2; j++)
		{
			scanf("%d", &key.mat2[i][j]);
		}
	}
	// creating the thread
	for(i = 0; i < key.ROW1; i++)
	{
		pthread_create((threadID+i), NULL, max_function, &key);
	}

	// joining the thread
	for(i = 0; i < key.ROW1; i++)
	{
		pthread_join(*(threadID+i), NULL);
	}

	printf("Entered  %dx%d matrix 1 \n", key.ROW1, key.COL1);


	for (i = 0; i < key.ROW1; i++)
	{
		for (j = 0; j < key.COL1; j++)
		{
			printf("%d\t", key.mat1[i][j]);
		}
		printf("\n");
	}
	printf("Entered  %dx%d matrix 2 \n", key.ROW2, key.COL2);


	for (i = 0; i < key.ROW2; i++)
	{
		for (j = 0; j < key.COL2; j++)
		{
			printf("%d\t", key.mat2[i][j]);
		}
		printf("\n");
	}

	printf("Resultant matric is %dx%d:  \n", key.ROW1, key.COL2);
	for (i = 0; i < key.ROW1; i++)
	{
		for (j = 0; j < key.COL2; j++)
		{
			printf("%d\t", key.res[i][j]);
		}
		printf("\n");
	}
	return 0;

}

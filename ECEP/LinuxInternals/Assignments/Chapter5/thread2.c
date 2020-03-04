#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define THREAD_VALUE_START 100
pthread_t thread_1;
pthread_t thread_2;
pthread_t thread_3;
int res[100][100];
int mat1[100][100];
int mat2[100][100];
int ROW1 = 3, ROW2 = 3, COL1 = 3, COL2 = 3;

pthread_mutex_t lock;

void* max_function(void *arg)
{

	int count;
	static int i, num = 1;
	static int m;
	int j, k;
	i = m;
	pthread_mutex_lock(&lock);
	ROW1 = m + 1;
	m++;
	for (; i < ROW1; i++) 
	{
		for (j = 0; j < COL2; j++)
		{
			res[i][j] = 0;
			for (k = 0; k < COL1; k++)
			{
				res[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}
//	sleep(2);
	pthread_mutex_unlock(&lock);
}

int main()
{
	pthread_t threadID;
	int threadvalue = THREAD_VALUE_START;
	int *result;
	void *exit_status;
	int loopindex;

	int i, j, i2, j2, i1, j1;
	printf("Enter the matrix 1 \n");
	
	for (i1 = 0; i1 < ROW2; i1++)
	{
		for (j1 = 0; j1 < COL2; j1++)
		{
			scanf("%d", &mat1[i1][j1]);
		}
	}
//        __fpurge(stdin);	
	printf("Enter the matrix 2 \n");
	for (i1 = 0; i1 < 3; i1++)
	{
		for (j1 = 0; j1 < 3; j1++)
		{
			//printf("i = %d\t j  = %d \n", i1, j1);
			scanf("%d", &mat2[i1][j1]);
		}
	}
	// creating the thread
	pthread_create(&thread_1, NULL, max_function, NULL);
	pthread_create(&thread_2, NULL, max_function, NULL);
	pthread_create(&thread_3, NULL, max_function, NULL);

	// joining the thread
	pthread_join(thread_1, NULL);
	pthread_join(thread_2, NULL);
	pthread_join(thread_3, NULL);

	printf("Resultant matric is :  \n");
	for (i = 0; i < ROW1; i++)
	{
		for (j = 0; j < COL2; j++)
		{
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}

}

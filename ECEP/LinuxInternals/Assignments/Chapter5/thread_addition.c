#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>

pthread_mutex_t lock;

struct array
{
	int arr[100];
	int i;
	int j;
	int max;
	int sum;
	int limit;
	int t_no;
};

void* thread_function(void *arg)
{
	struct array *ptr = arg;

	pthread_mutex_lock(&lock);

	for ( ; ptr->i < (ptr->j * (ptr->limit) / ptr->t_no); ptr->i++)
	{
		if (ptr->max < ptr->arr[ptr->i])
		{
			ptr->max = ptr->arr[ptr->i];
		}

		ptr->sum += ptr->arr[ptr->i];
	}
	++(ptr->j);
	pthread_mutex_unlock(&lock);
}



int main()
{
	int i, size, num;
	pthread_t *threadID;
	struct array key;
	key.i = 0;
	key.j = 1;
	key.sum = 0;

	printf("Enter the size of the array\n");
	scanf("%d", &size);

	key.limit = size;
        
	printf("Enter the number of threads\n");
	scanf("%d", &num);

	key.t_no = num;
        
	if (num > size)
	{
		printf("Error: Size of array should be more than no. of threads\n");
		exit (0);
	}

	printf("ENter the elements of the array\n");

	for (i = 0; i < size; i++)
	{
		scanf("%d", &key.arr[i]);
	}

	key.max = key.arr[0];
        
        threadID = malloc(sizeof(pthread_t) * num);

	for (i = 0; i < num; i++)
	{
		pthread_create((threadID + i), NULL, thread_function, &key);
	}

	for (i = 0; i < num; i++)
	{
		pthread_join(*(threadID + i), NULL);
	}

	pthread_mutex_destroy(&lock);
	
	printf("Maximum = %d\n", key.max);
	printf("Sum = %d\n", key.sum);
	
	return 0;
}

#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t thread_1;
pthread_t thread_2;
pthread_t thread_3;

int counter;
pthread_mutex_t lock;

void* thread_function(void *arg)
{
	pthread_mutex_lock(&lock);

	counter += 1;
	printf("\nJob %d started\n", counter);
	sleep(1);
	printf("\nJob %d finished\n", counter);
        
	pthread_mutex_unlock(&lock);
	return NULL;
}

int main()
{
	if (pthread_mutex_init(&lock, NULL) != 0)
	{
		printf("\nPthread: mutex init failed\n");
	}

	pthread_create(&thread_1, NULL, thread_function, NULL);
	pthread_create(&thread_2, NULL, thread_function, NULL);
	pthread_create(&thread_3, NULL, thread_function, NULL);

	pthread_join(thread_1, NULL);
	pthread_join(thread_2, NULL);
	pthread_join(thread_3, NULL);
	pthread_mutex_destroy(&lock);

	return 0;
}




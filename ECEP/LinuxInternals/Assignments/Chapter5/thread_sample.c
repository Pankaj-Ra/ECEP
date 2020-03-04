#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define THREAD_VALUE_START 100

void *thread_entry1_function(void * arg)
{
	int *thread_number;
	int loop;

	thread_number = (int *)arg;
	printf("Inside thread function\n");
	printf("Thread number is: %d\n", *thread_number);

	(*thread_number)++;
	printf("Increased thread number is: %d\n", *thread_number);

	return NULL;
}

void *thread_entry2_function(void * arg)
{
	printf("Hello its 2nd thread\n");
}

int main()
{
	pthread_t threadID;
	int threadvalue = THREAD_VALUE_START;
	int loopindex;

	pthread_create(&threadID, NULL, thread_entry1_function, &threadvalue);
        pthread_join(threadID, NULL);
	pthread_create(&threadID, NULL, thread_entry2_function, &threadvalue);
        pthread_join(threadID, NULL);


	printf("Back in main thread, thread value: %d\n", threadvalue);
        
	return 0;
}

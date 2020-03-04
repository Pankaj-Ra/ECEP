#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define THREAD_VALUE_START 7

void *thread_entry1_function(void * arg)
{
        printf("Inside thread 1\n");

	int *num;
	int i;
        int *total = (int *)malloc(sizeof(int));
	num = (int *)arg;
	*total = 1;

	for (i = *num; i > 0; i--)
	{
		*total = (*total) * i;
	}

	return total;

}

int main()
{
	pthread_t threadID;
	int threadvalue = THREAD_VALUE_START;
	void *exitstatus;
	int *factorial;

	pthread_create(&threadID, NULL, thread_entry1_function, &threadvalue);
	pthread_join(threadID, &exitstatus);
        
	factorial = (int *)exitstatus;

	printf("Back in main thread, factorial: %d\n", *factorial);

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

sem_t count;

void* fun(void *parm)
{
	int k = 5;
	pthread_t thread_id;
	int value;

	sem_wait(&count);
	sem_getvalue(&count, &value);
	printf("The semaphore count before loop: %d\n", value);
	while (k)
	{
		thread_id = pthread_self();
		printf("Thread %d with value of k = %d\n", (int)thread_id, k--);
		sleep(1);
	}
	sem_post(&count);
	sem_getvalue(&count, &value);
	printf("The semaphore count after loop: %d\n",value);
}

int main()
{
	int i;
	pthread_t tid[5];

	sem_init(&count, 0, 3);

	for (i = 0; i < 3; i++)
		pthread_create(&tid[i], NULL, &fun, NULL);

	for (i = 0; i < 3; i++)
		pthread_join(tid[i], NULL);

		return 0;
}
         


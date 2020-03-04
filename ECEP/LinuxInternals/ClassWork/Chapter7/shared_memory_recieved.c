#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SMSIZE 100

int main()
{
	int shmid, num;
	int *shm;
	key_t key;
	key = 'R';

	shmid = shmget(key, SMSIZE, IPC_CREAT | 0666);

	if (shmid < 0)
	{
		perror("shmget");
		exit(1);
	}
        
	shm = shmat(shmid, NULL, 0);
	if (shm < 0)
	{
		perror("shmat");
		exit(0);
	}
	else
	{
		printf("NUMBER:    %d\n", *shm);
		printf("FACTORIAL: %d\n", *(shm + 1));
	}

	shmdt(shm);
	shmctl(shmid, IPC_RMID, NULL);

	return 0;
}


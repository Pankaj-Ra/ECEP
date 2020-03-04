#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio_ext.h>
#include <sys/sem.h>
#define SMSIZE 100

int main()
{
	int pid1, pid2;
	int shmid, num;
	int *shm;
	int semid;
	struct sembuf sop;

	key_t key;
	key = 'R';

	semid = semget(0x20, 1, IPC_CREAT | 0666);

	//Initialize the smaphore value to 1
	semctl(semid, 0, SETVAL, 1);

	shmid = shmget(key, SMSIZE, IPC_CREAT | 0666);
	if (shmid < 0)
	{
		perror("shmget");
		exit(1);
	}



	pid1 = fork();

	if (pid1)
	{
		printf("Process 1: about to obtain lock\n");
		sop.sem_num = 0;
		sop.sem_op = -1;
		sop.sem_flg = 0;
		semop(semid, &sop, 1);
		printf("Process 1: lock obtained, entering the critical section now\n");

		sleep(1);
		printf("Writer1\n");
		shm = shmat(shmid, NULL, 0);
		*shm = 100;

		printf("Process 1: releases the lock now\n");
		sop.sem_num = 0;
		sop.sem_op = 1;
		sop.sem_flg = 0;
		semop(semid, &sop, 1);
		printf("Process 1: Lock released\n");

	}
	else
	{
		pid2 = fork();

		if (!pid2)
		{
			printf("Process 2: about to obtain lock\n");
			sop.sem_num = 0;
			sop.sem_op = -1;
			sop.sem_flg = 0;
			semop(semid, &sop, 1);
			printf("Process 2: lock obtained, entering the critical section now\n");

			sleep(1);
			printf("Writer2\n");
			shm = shmat(shmid, NULL, 0);
			*shm = 200;

			printf("Process 2: releases the lock now\n");
			sop.sem_num = 0;
			sop.sem_op = 1;
			sop.sem_flg = 0;
			semop(semid, &sop, 1);
			printf("Process 2: Lock released\n");

		}
		else
		{
			sleep(3);

			shm = shmat(shmid, NULL, 0);
			printf("NUMBER:    %d\n", (*shm));
			shmdt(shm);
			shmctl(shmid, IPC_RMID, NULL);

		}
	}


	return 0;
}



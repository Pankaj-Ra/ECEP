#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main()
{
	int semid, pid;
	struct sembuf sop;

	//create a semaphore
	semid = semget(0x20, 1, IPC_CREAT | 0666);

	//Initialize the smaphore value to 1
	semctl(semid, 0, SETVAL, 1);

	//Create new process
	pid = fork();
	if (!pid)
	{
		printf("Child: about to obtain lock\n");
		sop.sem_num = 0;
		sop.sem_op = -1;
		sop.sem_flg = 0;
		semop(semid, &sop, 1);
		printf("child: lock obtained, entering the critical section now\n");

		//Dummy critical section sleep as the operation
		sleep(5);

		printf("Child: releases the lock now\n");
		sop.sem_num = 0;
		sop.sem_op = 1;
		sop.sem_flg = 0;
		semop(semid, &sop, 1);
		printf("Child: Lock released\n");
	}
	else
	{
		printf("Parent: about to obtain lock\n");
		sop.sem_num = 0;
		sop.sem_op = -1;
		sop.sem_flg = 0;
		semop(semid, &sop, 1);
		printf("Parent: lock obtained, entering the critical section now\n");

		//Dummy critical section sleep as the operation
		sleep(5);

		printf("Parent: releases the lock now\n");
		sop.sem_num = 0;
		sop.sem_op = 1;
		sop.sem_flg = 0;
		semop(semid, &sop, 1);
		printf("Parent: Lock released\n");
	}

	return 0;
}
	

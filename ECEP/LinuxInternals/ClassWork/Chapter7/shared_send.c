#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SMSIZE 100

void factorial(int *shm, int shmid)
{
	int total = 1, i;
	int num;
	shm = shmat(shmid, NULL, 0);

	printf("Enter the value to get factorial\n");
	scanf("%d", &num);

	if (num)
	{
		for (i = num; i > 0; i--)
		{
			total = total * i;
		}

		printf("Factorial : %d\n", total);
		*shm = num;
		shm++;
		*shm = total;
		return;
	}
	printf("Factorial : %d\n", total);
	*shm = num;
	shm++;
	*shm = total;
	return;
}

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

	else
	{
		factorial(shm, shmid);
	}

	return 0;
}

		

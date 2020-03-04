#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SMSIZE 100

int prime(int fd[], int range)
{
	int prime = 2, j = 2, REMENDER = 1, COUNT;
       
       while (range)
       {
	       j = 2;
	       COUNT = prime;
	       while (j*j  <= COUNT)
	       {
		       REMENDER = (prime % j);
		       if (REMENDER == 0)
		       {
			       break;
		       }
		       j++;
	       }
	       if (REMENDER != 0)
	       {
		       write(fd[1], &prime, sizeof(prime));
		       range--;
	       }
	       prime++;
       }
       printf ("\n");
}

int factorial(int num)
{       
	int total = 1, i;

	if (num)
	{       
		for (i = num; i > 0; i--)
		{       
			total = total * i;
		}

		return total;
	}
}

int main()
{
	int pid, prim, len;
	int fd[2];
	pipe(fd);

	pid = fork();

	if (!pid)
	{
		int shmid, num;
		int *shm;
		int result;

		key_t key;
		key = 'R';

		read(fd[0], &len, sizeof(len));

		shmid = shmget(key, SMSIZE, IPC_CREAT | 0666);
		shm = shmat(shmid, NULL, 0);
		*shm = len;

		if (shmid < 0)
		{
			perror("shmget");
			exit(1);
		}

                printf("\e[1;35mIPC B/W Process 1 & Process 2 using PIPE\e[0m\n\n");
		printf("\e[1;32mChild Process 2: Prime numbers up to:\e[0m \e[1;35m%d\e[0m\n", len);
		while (len--)
		{
			read(fd[0], &prim, sizeof(prim));
			printf("\e[1;33m%d\e[0m\n", prim);

			result = factorial(prim);
			shm++;
			*shm = result;
		}

	}
	else
	{
START: 
		printf ("\e[1;32mParent Process 1: Enter the number to get prime series\e[0m\n");
		scanf ("%d",&len);

		write(fd[1], &len, sizeof(len));
		prime(fd, len);
	}

	return 0;
}


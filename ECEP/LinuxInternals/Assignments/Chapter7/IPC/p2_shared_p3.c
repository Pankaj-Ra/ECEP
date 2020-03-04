#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <sys/mman.h>

#define SMSIZE 100
#define FIFO_NAME "/tmp/pankaj"

void fibonachi(int fd, int N)
{
	unsigned long int i, NUM1=0, NUM2=1, GREAT=0;

	for (i = 0; i <= N + 1; i++)
	{       
		if (NUM1 <= N)
		{       
			GREAT = NUM1 + NUM2;
			
			write(fd, &NUM1, sizeof(NUM1));

			NUM1 = NUM2;
			NUM2 = GREAT;
		}
	}
	NUM1 = 10;
        write(fd, &NUM1, sizeof(NUM1));
	printf ("\n");
}

int main()
{
	int shmid, num;
	int *shm;
	int size;

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
		int fd;

		mknod(FIFO_NAME, 0666, 0);

		fd = open(FIFO_NAME, O_WRONLY);
		if (fd < 0)
		{
			perror("Open");
			exit(1);
		}


		printf("\n\e[1;35mIPC B/W Process P2 & P3 using Shared memory\e[0m\n\n");

		size = *shm;
		write(fd, shm, sizeof(*shm));
		while (size--)
		{
			shm++;
			printf("\e[1;32mfactorial:\e[0m \e[1;33m%d\e[0m\n", *shm);
                        
			write(fd, shm, sizeof(*shm));
			fibonachi(fd, *shm);
		}
	}

	shmdt(shm);
	shmctl(shmid, IPC_RMID, NULL);

	return 0;
}



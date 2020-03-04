#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main()
{
	int pid;

	int address;

	pid = vfork();

	if (!pid)
	{
		printf("child pid: %d  child ppid: %d\n", getpid(), getppid());
		printf("Memory location: %p\n", &address);
		sleep(5);
		exit(0);
	}
	else
	{
		printf("parent pid: %d  child ppid: %d\n", getpid(), getppid());
		printf("Memory location: %p\n", &address);
	}

	return 0;
}


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	int pid;

	pid = fork();

	if (pid == 0)
	{
		while (1)
		{
			printf("Never say die\n");
			printf("child pid: %d child ppid: %d\n", getpid(), getppid());
		}
	}
	else
	{
		sleep(2);
		printf("Hello\n");
		printf("parent pid: %d parent ppid: %d\n", getpid(), getppid());
		sleep(2);
	}
	return 0;
}

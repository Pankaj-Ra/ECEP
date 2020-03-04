#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	int pid;

	pid = fork();

	if (pid == 0)
	{
		//Child
		printf("Child1 pid: %d Child1 ppid: %d\n", getpid(), getppid()); 
		pid = fork();

		if (pid == 0)
		{
			printf("Child2 pid: %d Child2 ppid: %d\n\n", getpid(), getppid());
		}
		else
		{
			printf("Child parent pid: %d  Child parent ppid: %d\n", getpid(), getppid());
		}
	}
	else
	{
		printf("\nparent pid: %d parent ppid: %d\n", getpid(), getppid());
	}

	return 0;
}



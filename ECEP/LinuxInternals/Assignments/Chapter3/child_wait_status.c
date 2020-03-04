#include <stdio.h>
#include <stdio_ext.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int pid;
	int status;

	pid = fork();

	if (!pid)
	{
		printf("child3 pid: %d child ppid %d: \n", getpid(), getppid());

	}

	else
	{
		printf("\n<<<pairent is waiting>>>\n\n");
		printf("Parent pid: %d child ppid %d: \n\n", getpid(), getppid());

		pid = fork();

		if (!pid)
		{
			printf("child2 pid: %d child ppid %d: \n", getpid(), getppid());
		}
		else
		{

			pid = fork();

			if (!pid)
			{
				printf("child1 pid: %d child ppid %d: \n", getpid(), getppid());
			}
			else
			{

				wait(&status);

				if (WIFEXITED(status)) {
					printf("exited, status=%d\n", WEXITSTATUS(status));
				} else if (WIFSIGNALED(status)) {
					printf("killed by signal %d\n", WTERMSIG(status));
				} else if (WIFSTOPPED(status)) {
					printf("stopped by signal %d\n", WSTOPSIG(status));
				} else if (WIFCONTINUED(status)) {
					printf("continued\n");
				}

				wait(&status);

				if (WIFEXITED(status)) {
					printf("exited, status=%d\n", WEXITSTATUS(status));
				} else if (WIFSIGNALED(status)) {
					printf("killed by signal %d\n", WTERMSIG(status));
				} else if (WIFSTOPPED(status)) {
					printf("stopped by signal %d\n", WSTOPSIG(status));
				} else if (WIFCONTINUED(status)) {
					printf("continued\n");
				}

				wait(&status);

				if (WIFEXITED(status)) {
					printf("exited, status=%d\n", WEXITSTATUS(status));
				} else if (WIFSIGNALED(status)) {
					printf("killed by signal %d\n", WTERMSIG(status));
				} else if (WIFSTOPPED(status)) {
					printf("stopped by signal %d\n", WSTOPSIG(status));
				} else if (WIFCONTINUED(status)) {
					printf("continued\n");
				}
				printf("\n<<<pairent is dying>>>\n\n");
			}
		}
	}

	return 0;
}



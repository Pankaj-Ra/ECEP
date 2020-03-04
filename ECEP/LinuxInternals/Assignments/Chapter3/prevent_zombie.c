#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int pid;

	pid = fork();

	if (pid == 0)
	{
		printf("child pid: %d  child ppid: %d\n", getpid(), getppid());
		printf("Child dying \n");
	}
	else
	{
		waitpid(pid, NULL, WCONTINUED);

		printf("<<<parent dying>>>\n");
		sleep(10);
		printf("<<<parent died>>>\n");
	}

	return 0;
}


		

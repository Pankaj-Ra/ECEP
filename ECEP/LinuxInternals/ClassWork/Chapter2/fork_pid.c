#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
int main()
{
	int pid;
	int c, p;

	pid = fork();

	if (pid == 0)
	{
		printf("Hello\n");
		printf("Child pid: %d Child pid: %d\n", getpid(), getppid());
		printf("Enter the child value\n");
		scanf("%d", &c);
	}
	else
	{
		printf("World\n");
		printf("Parient pid: %d Parient pid: %d\n", getpid(), getppid());
		printf("Enter the parient value\n");
		scanf("%d", &p);
	}

	return 0;
}

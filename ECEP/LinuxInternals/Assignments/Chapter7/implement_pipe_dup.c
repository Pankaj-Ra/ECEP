#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>

int main()
{
	int pid;
	int fd1[2];
	int fd2[2];
	int fd;

	char buff[] = " 2024";
	fd = open("temp.txt", O_RDWR | O_TRUNC, 0666);
	dup2(fd, 1);
	execlp("lsof", "lsof", "-a", "-p", (buff + 1), "-d", "^txt,^mem", NULL);

	pipe(fd1);
	pipe(fd2);

	pid = fork();

	if (!pid)
	{
		printf("Child1: pid %d ppid %d\n", getpid(), getppid());
		close(fd2[0]);
		close(fd2[1]);
		close(fd1[0]);
		dup2(fd1[1], 1);
		execl("/usr/bin/ls","ls", "--color", "-l",  NULL);

	}
	else
	{
		printf("Parent: pid %d ppid %d\n", getpid(), getppid());
		pid = fork();

		if (!pid)
		{
			printf("Child2: pid %d ppid %d\n", getpid(), getppid());
			close(fd1[1]);
			dup2(fd1[0], 0);
			close(fd2[0]);
			dup2(fd2[1], 1);
			execl("/usr/bin/grep","grep", "pankaj", NULL);
		}
		else
		{
			pid = fork();

			if (!pid)
			{
				printf("Child3: pid %d ppid %d\n", getpid(), getppid());
				close(fd1[0]);
				close(fd1[1]);
				close(fd2[1]);
				dup2(fd2[0], 0);
				execl("/usr/bin/wc", "wc", "-l", NULL);
			}
			else
			{
				close(fd1[1]);
				close(fd2[1]);
				close(fd1[0]);
				close(fd2[0]);
				wait();
			}
		}

	}
}


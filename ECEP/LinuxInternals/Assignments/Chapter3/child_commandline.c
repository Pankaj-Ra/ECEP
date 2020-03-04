#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
	int pid;
	pid = fork();

	if (!pid)
	{
		if (!strcmp(argv[1], "ls"))
		{
			execv("/bin/ls", (argv+1));
		}
		else if (!strcmp(argv[1], "man"))
		{
			execv("/usr/bin/man", (argv+1));
		}
		else if (!strcmp(argv[1], "wc"))
		{
			execv("/usr/bin/wc", (argv+1));
		}
	}
	else
	{
		printf("<<<Parent dying>>>\n\n");
		wait();
		printf("\n<<<Parent died>>>\n");
	}

	return 0;
}

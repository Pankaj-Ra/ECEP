#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main()
{
	int pid, num, len;
        int fd[2];
	char str[50];

	pipe(fd);
	
	pid = fork();

	if (!pid)
	{
		printf("Enter the string\n");
		scanf("%s", str);
		len = strlen(str) + 1;

                write(fd[1], &len, sizeof(len));
		write(fd[1], str, len);
	}
	else
	{
		read(fd[0], &len, sizeof(len));
		read(fd[0], str, len);
		printf("copy: = %s\n", str);
	}

	return 0;
}




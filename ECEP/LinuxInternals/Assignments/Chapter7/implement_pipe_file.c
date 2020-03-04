#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio_ext.h>

int main()
{
	int pid, num, read_len, recv, len;
	int fd[2];
	char str[50];
	char buff;
	int fs1, fs2;

	pipe(fd);

	if ((fs1 = open("source.txt", O_CREAT | O_RDONLY)) == -1)
	{
		perror("open");
		return -1;
	}
	if ((fs2 = open("dest.txt", O_CREAT | O_WRONLY)) == -1)
	{
		perror("open");
		return -1;
	}

	pid = fork();

	if (!pid)
	{
		system("ls -l > source.txt");
                
		while (((read_len = read(fs1, &buff, sizeof(buff))) != -1) && (read_len != 0))
		{
			write(fd[1], &buff, sizeof(buff));
		}
		printf("child diead\n");
		buff = '\0';
		write(fd[1], &buff, sizeof(buff));
	}
	else
	{
		while (1)
		{
			recv = read(fd[0], &buff, sizeof(buff));
			if (buff == '\0')
			{
				break;
			}
			write(fs2, &buff, sizeof(buff));
		}

		printf("Enter the file you want to search like: <grep file1>\n");
		wait();
		__fpurge(stdin);

		pid = fork();
		
		if (!pid)
		{
			scanf("%s", &str);
			system(str);
		}

	}

	return 0;
}


#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define BUFF_SIZE 100

int main(int argc, char *argv[])
{
	int fd1, fd2, read_len;
	char choice;
	char buff[BUFF_SIZE];
	struct stat mode;

	if (argc < 3)
	{
		printf("Usage: ./a.out <src> <dst>\n");
		return 1;
	}

	if ((fd1 = open(argv[1], O_RDONLY)) == -1)
	{
		perror("open");
		return -1;
	}

	fstat(fd1, &mode);

	if ((fd2 = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, mode.st_mode)) == -1)
	{
		if (errno == EEXIST)
		{
			do
			{
				printf("FILE EXISTS! Do you want to overwrite (Y/N)? \n");
				scanf("%c", &choice);

				getchar();
				
				if ((choice == 'n') || (choice == 'N'))
				{
					return 0;
				}
				else if ((choice == 'y') || (choice == 'Y'))
				{
					if ((fd2 = open(argv[2], O_WRONLY | O_TRUNC, mode.st_mode)) == -1)
					{
						perror("open");
						return -1;
					}
					else
					{
						break;
					}
				}
			}while(1);
		}
		else
		{
			perror("open");
			return -1;
		}
	}

	while (((read_len = read(fd1, buff, BUFF_SIZE)) != -1) && (read_len != 0))
	{
		if (write(fd2, buff, read_len) == -1)
		{
			perror("write");
			return -1;
		}
	}

	close(fd1);
	close(fd2);

	return 0;
}



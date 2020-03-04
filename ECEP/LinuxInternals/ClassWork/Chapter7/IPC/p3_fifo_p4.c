#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

#define FIFO_NAME "/tmp/pankaj"

int main()
{
	int fd, size, fibo;
	unsigned long int num;

	fd = open(FIFO_NAME, O_RDONLY);

	if (fd < 0)
	{
		perror("Open");
		exit(1);
	}

	else
	{
		read(fd, &size, sizeof(size));
		printf("\n\e[1;35mIPC B/W Process P3 & Process P4 using FIFO\e[0m\n\n");

		while (size--)
		{
			read(fd, &fibo, sizeof(fibo));
			printf("\e[1;32mFibonachi series up to\e[0m \e[1;35m%d:\e[0m\n", fibo);

			while (1)
			{
				read(fd, &num, sizeof(num));
				if (num == 10)
				{
					break;
				}
				printf("\e[1;33m%d\e[0m\t", num);
			}
			printf("\n\n");
		}
	}
	return 0;
}


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
	int fd, pp;
//	char send_string[MAX_STRING_LEN];

	mknod(FIFO_NAME, 0666, 0);

	fd = open(FIFO_NAME, O_WRONLY);
	if (fd < 0)
	{
		perror("Open");
		exit(1);
	}

	else
	{
		pp = 100;
		write(fd, &pp, sizeof(pp));
		pp = 200;
		write(fd, &pp, sizeof(pp));
		printf("Value send to FIFO\n");
	}

	return 0;
}
	


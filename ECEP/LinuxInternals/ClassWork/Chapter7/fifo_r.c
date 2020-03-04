#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

#define FIFO_NAME "/tmp/pankaj"
#define MAX_STRING_LEN 80

int main()
{
	int fd, pp;
        
	fd = open(FIFO_NAME, O_RDONLY);

	if (fd < 0)
	{
		perror("Open");
		exit(1);
	}

	else
	{
		read(fd, &pp, sizeof(pp));
		printf("FIFO_read pp: %d\n", pp);
		read(fd, &pp, sizeof(pp));
		printf("FIFO_read pp: %d\n", pp);
	}
	return 0;
}
		
		
	



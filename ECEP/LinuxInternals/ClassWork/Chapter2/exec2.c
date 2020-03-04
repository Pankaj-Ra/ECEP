#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{

	printf("After exec My  id is %d\n", getpid());
	printf("After exec My parent process id %d\n", getppid());

	printf("Exec ends\n\n");

	return 0;
}

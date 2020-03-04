#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{
	printf("\nBefore exec my id is %d\n", getpid());
	printf("My parent process's id is %d\n", getppid());

	printf("Exec starts\n");

        /*Replace <path> with the current path in witch exec2 is there*/

	execl("/home/pankaj/ECEP/LinuxInternals/ClassWork/Chapter2/exec2", "exec2", (char *)0);
	printf("this wont print\n");

	return 0;
}




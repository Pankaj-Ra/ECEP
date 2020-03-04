#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

int main()
{
	int sec, usec;
	struct rusage usage;

	int pid = fork();

	if (!pid)
	{
		printf("Child : pid %d\n", getpid());
	}
	else
	{
		wait();
		printf("Parent : pid %d\n", getpid());

		getrusage(RUSAGE_SELF, &usage);
		printf("Maximum resident set size parent = %lu\n", usage.ru_maxrss);
		printf("Resource usage by parent = %lu\n", usage.ru_idrss);

		getrusage(RUSAGE_CHILDREN, &usage);
		printf("Maximum resident set size child = %lu\n", usage.ru_maxrss);
		printf("Resource usage by child = %lu\n", usage.ru_idrss);
	}

	return 0;
}



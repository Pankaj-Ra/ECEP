#include <unistd.h>
#include <stdio.h>
#include <time.h>

int main()
{
	unsigned int sec;

	printf("How long you want to sleep\n");
	scanf("%d", &sec);
        
	printf("Wait for %d sec\n", sec);

	sleep(sec);

        printf("Wake Up!!!\n");

	struct timespec req;

	req.tv_nsec = 99999;

	req.tv_sec = 0;

	struct timespec rem;

	printf("Time for nano sleep  99999 nsec\n");

	nanosleep(&req, &rem);

	printf("Wake up!!!\n");

	return 0;
}

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void my_signal_handler(int signo)
{
	if (signo == SIGUSR1)
		printf("Received SIGUSR1\n");
	else if (signo == SIGUSR2)
		printf("Received SIGUSR2\n");
	else
		printf("ERROR: Sorry wrong signal\n");
}

int main()
{
	int mypid;

	/* Registering for SIGUSR1 & SIGUSR2 */
	if (signal(SIGUSR1, my_signal_handler) == SIG_ERR)
		printf("Cannot catch this signal -1\n");
	if (signal(SIGUSR2, my_signal_handler) == SIG_ERR)
		printf("canot catch this signal -2\n");

	printf("Waiting Pid = %d\n", getpid());
	//asyncronous handling
	pause();

	/*polling
	  while (1)
	  {
	  printf("Waiting Pid = %d\n", getpid());
	  sleep(3);
	  }*/

	printf("Signal handeled iam exiting\n");
}


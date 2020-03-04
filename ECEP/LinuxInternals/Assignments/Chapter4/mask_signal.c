#include <stdio.h>
#include <unistd.h>
#include <signal.h>

struct sigaction new_act;

void my_signal_handler(int signo)
{
	int i = 10;

	if (signo == SIGUSR1){
		printf("Received SIGUSR1\n");
		while (i--)
		{
			printf("Iam working in sig1\n");
			sleep(2);
		}}

	else if (signo == SIGUSR2){
		printf("Received SIGUSR2\n");
		while (i--)
		{
			printf("Iam working in sig2\n");
			sleep(2);
		}}
	else
		printf("ERROR: Sorry wrong signal\n");
}

int main()
{
	sigset_t val;

	sigaddset(&val, SIGUSR2);

	memset(&new_act, 0, sizeof(new_act));

	//where ever alarm comes call by handler
	new_act.sa_handler = my_signal_handler;
	new_act.sa_mask = val;

	sigaction(SIGUSR1, &new_act, NULL);
	sigaction(SIGUSR2, &new_act, NULL);

	printf("Waiting Pid = %d\n", getpid());
	pause();
	printf("Waiting Pid = %d\n", getpid());
	pause();

	return 0;
}


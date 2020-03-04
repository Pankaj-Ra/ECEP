#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int num;

void factorial(int num)
{
	int total = 1, i;

	if (num)
	{
		for (i = num; i > 0; i--)
		{
			total = total * i;
		}

		printf("Factorial : %d\n", total);
		return;
	}
	printf("Factorial : %d\n", total);
	return;
}

void my_signal_handler(int signo)
{
	if (signo == SIGUSR1){
		printf("Received SIGUSR1\n");
		factorial(num);}
	else
		printf("ERROR: Sorry wrong signal\n");
}

int main()
{
	int mypid;

	/* Registering for SIGUSR1 & SIGUSR2 */
	if (signal(SIGUSR1, my_signal_handler) == SIG_ERR)
		printf("Cannot catch this signal -1\n");

	printf("Pid = %d\n", getpid());

	printf("Enter the value to get factorial\n");
	scanf("%d", &num);
	printf("Waiting.....for signal\n");

	//asyncronous handling
	pause();

	printf("Signal handeled iam exiting\n");
	return 0;
}


#include <stdio.h>
#include <unistd.h>
#include <signal.h>

struct sigaction new_act;

void my_signal_handler(int signo, siginfo_t *signal, void *context)
{
        printf("Segmentation fault\n");
	printf("Address causing fault: %p\n", (signal->si_addr));
	exit(0);
}

int main()
{
	int b;
	int *ptr;
	ptr = 0xabcdef;

	printf("Address Before fault: %p\n", ptr);

	memset(&new_act, 0, sizeof(new_act));

	//where ever alarm comes call by handler
	new_act.sa_sigaction = my_signal_handler;
	new_act.sa_flags = SA_SIGINFO;

	sigaction(SIGSEGV, &new_act, NULL);
        
	printf("Waiting Pid = %d\n", getpid());

	printf("Before\n");
	*ptr = b;
	printf("After\n");

	return 0;
}


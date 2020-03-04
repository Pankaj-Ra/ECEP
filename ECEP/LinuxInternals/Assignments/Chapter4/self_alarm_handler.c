#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

struct sigaction new_act, old_act;

void alarm_handler(int not_using)
{
	printf("Alarm occured inside my handler\n");

	sigaction(SIGALRM, &old_act, NULL);
	alarm(5);
}

int main()
{
	memset(&new_act, 0, sizeof(new_act));
        
	//where ever alarm comes call by handler
	new_act.sa_sigaction = alarm_handler;
	sigaction(SIGALRM, &new_act, &old_act);

	printf("Calling alarm for 5 sec your handler\n");
	alarm(5);
        
	pause();
	pause();
	//while(1);

	printf("IT will never print\n");

	return 0;
}

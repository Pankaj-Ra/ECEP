#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <stdio_ext.h>

struct sigaction new_act;

void alarm_handler(int not_using)
{
	printf("ALARM IS STILL ACTIVE\n\n");
}

int main(int argc, char *argv[])
{
	int i, curr_s, alm_s, wakein_s, hr, mn, sc;
	char sec[3], min[3], hour[3];
	char check;

	struct timeval v;

	gettimeofday(&v, NULL);

	struct tm *t = localtime(&v.tv_sec);

	printf("Time   :%lu\n", v.tv_sec);
	printf("Second :%d\n", t->tm_sec);
	printf("Min    :%d\n", t->tm_min);
	printf("Hour   :%d\n", t->tm_hour);
         
        curr_s = t->tm_sec + (60 * t->tm_min) + (3600 * t->tm_hour);

	for (i = 0; i < 2; i++)
	{
		hour[i] = *((argv[1]) + i);
		min[i] = *((argv[1]) + (i + 3));
		sec[i] = *((argv[1]) + (i + 6));
	}
	hour[i] = '\0';
	min[i] = '\0';
	sec[i] = '\0';

	hr = atoi(hour);
	mn = atoi(min);
	sc = atoi(sec);

	printf("Wake up time: %d %d %d\n", hr, mn, sc);
	if ((hr > 24) || (mn > 60) || (sc > 60))
	{
		printf("ERROR: enter in 24 hour format: <24:60:60>\n");
		exit(0);
	}

	alm_s = sc + (60 * mn) + (3600 * hr);

	wakein_s = alm_s - curr_s;

	if (wakein_s < 0)
	{
		printf("Error: You over slept its already past\n");
		return -1;
	}

	memset(&new_act, 0, sizeof(new_act));

	//where ever alarm comes call by handler
	new_act.sa_sigaction = alarm_handler;
	sigaction(SIGALRM, &new_act, NULL);
        
	printf("ALARM will go off after %d sec\n\n", wakein_s);
	alarm(wakein_s);

	while (1)
	{
		pause();
		printf("WAKE UP WAKE UP!!!!!\n\n");
		printf("=>> Enter '0' to terminate ALARM\n=>> press any key to SNOOZE 10 sec\n");
		__fpurge(stdin);
		scanf("%c", &check);
		if (check == '0')
		{
			break;
		}

		printf("\n\nSNOOZE ZZZzzzzz\n\n");
		alarm(10);
	}

	printf("ALARM is TERMINATED!!!!\n");
	return 0;
}


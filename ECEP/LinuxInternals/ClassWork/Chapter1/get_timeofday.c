#include <stdio.h>
#include <sys/time.h>
#include <time.h>

int main()
{
	struct timeval v;

	gettimeofday(&v, NULL);

	printf("Time   :%lu\n", v.tv_sec);

        struct tm *t = localtime(&v.tv_sec);

	printf("Second :%d\n", t->tm_sec);
	printf("Min    :%d\n", t->tm_min);
	printf("Hour   :%d\n", t->tm_hour);
	printf("Mday   :%d\n", t->tm_mday);
	printf("Month  :%d\n", t->tm_mon);
	printf("Year   :%d\n", t->tm_year);
	printf("Wday   :%d\n", t->tm_wday);
	printf("Yday   :%d\n", t->tm_yday);
	printf("Isdst  :%d\n", t->tm_isdst);

	return 0;
}

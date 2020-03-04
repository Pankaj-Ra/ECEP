#include <stdio.h>
#include <string.h>

int main()
{
	char *loc;

	loc = strstr("helloworld", "world");

	if(loc != NULL)
	{
		printf("Found sunstring\n");
		puts(loc);
	}

	return 0;
}

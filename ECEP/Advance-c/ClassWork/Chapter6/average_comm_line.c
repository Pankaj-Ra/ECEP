#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int i;
	double  sum = 0, avg;
	for (i = 1; i < argc; i++)
	{
		printf("argv[%d]: %s\n", i, argv[i]);
        sum += atof(argv[i]);
	}

	avg = sum / (argc - 1);
	printf("Average: %f\n", avg);

	return 0;
}


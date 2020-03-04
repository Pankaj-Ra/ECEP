#include <stdio.h>
int main()
{
	int num, rem;

lable:	printf ("Enter the day between 1-365\n");
		scanf ("%d",&num);
		if (num > 365 || num < 1)
		{
			printf ("ERROR\n");
			goto lable;
		}
		rem = num % 7;
		if (rem == 0)
			printf ("Sunday\n");
		if (rem == 1)
			printf ("Monday\n");
		if (rem == 2)
			printf ("Tuesday\n");
		if (rem == 3)
			printf ("Wednesday\n");
		if (rem == 4)
			printf ("Thursday\n");
		if (rem == 5)
			printf ("Friday\n");
		if (rem == 6)
			printf ("Saturday\n");

		return 0;
}



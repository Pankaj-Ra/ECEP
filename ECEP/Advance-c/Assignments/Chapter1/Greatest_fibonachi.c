#include <stdio.h>
int main()
{
	int limit, i, first = 0, second = 1, GREAT = 0, temp = 0;

	printf ("Enter the Number\n");
	scanf ("%d",&limit);
	for (i = 0; i <= limit; i++)
	{
		if (first <= limit)
		{
		GREAT = first + second;							//SUM (next value) is equal to the addition of last two values
		temp = first;
		first = second;									
		second = GREAT;
		}
		else
		{
			break;
		}
	}
	if (first > limit)
	{
		printf ("Greatest Fibonacci No is :%d\t",temp);	//temp is printed instead of GREAT, because it also includes 0, 1
	}
	if (first <= limit)
	{
		printf ("Greatest Fibonacci No is :%d\t",first);
	}
	printf ("\n");

	return 0;
}


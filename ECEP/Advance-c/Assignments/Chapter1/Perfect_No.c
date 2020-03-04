#include <stdio.h>
int main()
{
	int num, j, ADD = 0, REM;

	printf ("Enter the Number\n");
	scanf ("%d",&num);
		for (j = 1; j < num; j++)					//to check the perfect number , we first findout its factors
		{
			REM = (num % j);
			if (REM == 0)
			{
				ADD = ADD + j;				//sum of factors of that number should be equal to the number itself
			}
		}
		if (ADD == num)
		{
			printf ("Perfect No");
		}
		else
		{
			printf ("Not A Perfect no");
		}
	printf ("\n");
	
	return 0;
}




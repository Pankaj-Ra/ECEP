#include <stdio.h>
int main()
{
	int i, count, array[99], Q, rem;

	printf ("Enter Variable count\n");
	scanf ("%d",&count);
	printf ("Enter the variables\n");
	for (i = 0; i < count; i++)						//for loop is used to store values given by user 
	{
	  scanf ("%d",&array[i]);
	}
	Q = count / 2;								//count is divided by 2 get middle value 	
	rem = count % 2;								//Remender is used to check if there is 1 median or 2
	if (rem == 0)
	{
		printf ("There are two medians = %d, %d\n",array[Q-1], array[Q]);
	}
	else
	{
		printf ("Median is = %d\n",array[Q]);
	}

	return 0;
}





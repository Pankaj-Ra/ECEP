#include <stdio.h>
#include <math.h>
int main()
{
	int i, j, k,  limit, count, count1, multiplier, multiple;

	printf ("Enter the LIMIT\n");
	scanf ("%d",&limit);
	int array[limit];
	for (i = 0; i <= limit; i++)
	{
		array[i] = i;
//		if (i % 10 != 0)
			printf("%d ",array[i]);
//		else
//			printf("\n%d\t",array[i]);
	}
//	count = sqrt(limit);
	for (i = 2; i*i <= limit; i++)
	{
		multiplier = array[i];
		if (multiplier != 0)
		{
			count1 = limit/multiplier;
			printf("\n\nEliminating multiple of = %d\n\n",multiplier);
			for (j = 2; j <= count1; j++)
			{
				multiple = multiplier * j;
				array[multiple] = 0;
			}
			for (k =2; k <= limit; k++)
			{
			//	if (k % 10 != 0)
			//	{
					if (array[k] != 0)
					{
						printf ("%d ",array[k]);
					}
			//	}
			/*	else
				{
					printf("\n");
					if (array[k] != 0)
					{
						printf("%d\t",array[k]);
					}
				}*/
			}
		}
		else
		{
			continue;
		}
	}
	printf ("\n\nPrime numbers up to %d are :\n",limit);
	for (i = 2; i <= limit; i++)
	{
		if (array[i] != 0)
		{
			printf ("%d ",array[i]);
		}
	}
	printf ("\n");

	return 0;
}




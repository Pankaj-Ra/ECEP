				/* Print output in sorted order without copying sorting or editiing float array*/
#include <stdio.h>

int main()
{
	//Declare variables and array
	int i, j, count;
	float small, large;
	float smallest, largest;
	float store[50];

	//Getting number count from user
	printf("Enter the count\n");
	scanf("%d",&count);

	//Populating the array
	printf("Enter the values\n");
	for (i = 0; i < count; i++)
	{
		scanf("%f",&store[i]);
	}

	//Finding largest value in array and store in variable largest
	largest = store[0];
	for (i = 0; i < count - 1; i++)
	{
		if (largest < store[i + 1])
		{
			largest = store[i + 1];
		}
	}

	//Finding smallest values and printing
	printf("Values in storted order are:\n");
	for (i = 0; i < count; i++)
	{
		small = largest;
		for (j = 0; j < count; j++)
		{
			large = store[j];
			if (small > large)
			{
				//if current value is larger than the previus smallest value than store in varaiable small
				if ((i == 0) || (large > smallest))
				{
					small = large;
				}
			}
		}
		//Printing next smallest value than previous
		smallest = small;

		//Find repeating numbers and print
		for (j = 0; j < count; j++)
		{
			if (smallest == store[j])
			{
				printf("%f\t", smallest);
			}
		}

		//Exit condition if its a largest value
		if (smallest == largest)
		{
			break;
		}
	}
	printf("\n");

	return 0;
}


						/* variance calculation without static/dynamic arrays */
#include <stdio.h>

int main()
{
	//Declare the array and variables
	float array[20], sum = 0, avg, avgdiff = 0, variance;
	int i, count;

	printf("Enter the length of the array\n");
	scanf("%d",&count);
	printf("Enter the values\n");

	//populating the array and calculating sum of all elements
	for ( i = 0; i < count; i++)
	{
		scanf("%f",&array[i]);
		sum += array[i];
	}
	avg = sum / count;

	//calculating the sum of diff of avg and array elements
	for ( i = 0; i < count; i++)
	{
		avgdiff += (array[i] - avg) * (array[i] - avg);
	}
	variance = avgdiff / count;
    printf("variance for the given values is: \n%f\n", variance);

    return 0;
}
	


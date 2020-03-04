#include <stdio.h>
#include <stdlib.h>

float variance_dynamic(int count)
{
	int i;
	float *p = malloc(count * sizeof(float));
	float sum = 0, avg, avgdiff = 0, variance;

        printf("Enter the values for dynamic array\n");
	for (i = 0; i < count; i++)
	{
		scanf("%f", (p + i));
		sum += *(p + i);
	}

	avg = sum / count;

	for (i = 0; i < count; i++)
	{
		avgdiff += ((*(p + i) - avg) * (*(p + i) - avg));
	}

	variance = avgdiff / count;

	return variance;
}

float variance_static(int count)
{
	int i;
	float array[count];
	float sum = 0, avg, avgdiff = 0, variance;

        printf("Enter the values for static array\n");
	for (i = 0; i < count; i++)
	{
		scanf("%f", &array[i]);
		sum += array[i];
	}

	avg = sum / count;

	for (i = 0; i < count; i++)
	{
		avgdiff += ((array[i] - avg) * (array[i] - avg));
	}

	variance = avgdiff / count;

	return variance;
}


int main()
{
	int size;
	float dynamic;
	float static_array;

	printf("Enter the number count\n");
	scanf("%d",&size);

	dynamic = variance_dynamic(size);

	printf("variance calculated using dynamic array:\t%f\n", dynamic);

	static_array = variance_static(size);

	printf("variance calculated using static array: \t%f\n", static_array);

	return 0;
}







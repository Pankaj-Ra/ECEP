#include<stdio.h>
main()
{
	int size, i, j, smallest, largest, result; 
	printf ("Enter the size of array\n");
	scanf ("%d",&size);
	printf ("Enter the values\n");
	int a[size];
	for (i = 0;i < size;i++)
	{
		scanf ("%d",&a[i]);
	}
		smallest = a[0];
		largest = a[0];
		for (j = 1;j < size;j++)
		{
			if (smallest > a[j])
			{
				smallest = a[j];
			}
			if (largest < a[j])
			{
				largest = a[j];
			}
		}
		result = largest - smallest;
		printf ("Difference of %d and %d is = %d",largest, smallest, result);
	printf ("\n");
}




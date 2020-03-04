#include <stdio.h>
#define array_size(array) (sizeof(array)/sizeof(*array))
int print_array(int *ptr, int size);
int print_array(int *ptr, int size)
{
	int sum = 0, i = 0;
	for (i = 0; i < size; i++)
	{
		ptr = ptr +1;
		sum = sum + *ptr;
	}
	printf ("\n");
	return (sum);
}
int main()
{
	int n, i;
	printf ("Enter the limit of array\n");
	scanf ("%d\n",&n);
	int array[n];
	for (i = 0;i < n; i++)
	{
		scanf ("%d",&array[i]);
	}
	printf ("SUM = %d\n",print_array(array, array_size(array)));

	return 0;
}



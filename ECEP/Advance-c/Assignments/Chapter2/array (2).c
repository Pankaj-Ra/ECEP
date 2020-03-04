#include <stdio.h>
#define array_size(array) (sizeof(array)/sizeof(*array))
void print_array(int *ptr, int size);
void print_array(int *ptr, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf ("%d\t",*(ptr + i));
	}
	printf ("\n");
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
	print_array(array, array_size(array));

	return 0;
}



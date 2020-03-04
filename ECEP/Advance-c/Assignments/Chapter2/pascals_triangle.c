#include <stdio.h>
int print_triangle(int size);
int print_triangle(int size)
{
	int i, j, a[size] , b[size];
	for (j = 0; j < size; j++)
	{
		for (i = 0; i < size - j; i++)
		{
				printf("   ");
		}
		for (i = 0; i <= j; i++)
		{ 
           b[0] = a[0] = 1;
		   b[j] = a[j] = 1;
		if (i != 0 && i != j)
		{
			b[i] = a[i-1] + a[i];
		}
			printf("   %d  ",b[i]);
		}
		for (i = 0; i < j; i++)
		{
			a[i] = b[i];
		}
		printf("\n");
	}
}
int main()
{
	int size;
	printf("Enter the number of rows of pascals triangle\n");
	scanf("%d",&size);
	print_triangle(size);
}
		



            




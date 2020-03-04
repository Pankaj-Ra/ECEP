#include <stdio.h>

int main()
{
	int a[10];

	printf("The address difference is %p\n", (&a[1] - &a[0]));
}

#include <stdio.h>

void swap(void *vptr1, void *vptr2, int size)
{

	while (size--)
	{
		*(char *)vptr2 = *(char *)vptr1;
		vptr1 += sizeof(char);
		vptr2 += sizeof(char);
	}
}

int main()
{
	int a = 10, b = 0;

	printf("Before:\na: %d\tb: %d\n", a, b);

	swap(&a, &b, sizeof(int));

	printf("After:\na: %d\tb: %d\n", a, b);

	float f1 = 12.32, f2 = 0;

	printf("Before:\nf1: %f\tf2: %f\n", f1, f2);

	swap(&f1, &f2, sizeof(float));

	printf("After:\nf1 %f\tf2: %f\n", f1, f2);

	return 0;
}


#include <stdio.h>

#define SIZEOF(x) ((char *)(&x + 1) - (char *)&x)

int main()
{
	int i, a, b, c;
	float f;
	double d;

	a = SIZEOF(i);

	printf("size of int: = %d\n", a);

	b = SIZEOF(f);

	printf("size of float: = %d\n", b);
                   
	c = SIZEOF(d);

	printf("size of double: = %d\n", c);

	return 0;
}

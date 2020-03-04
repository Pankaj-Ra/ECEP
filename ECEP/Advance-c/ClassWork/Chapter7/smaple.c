#include <stdio.h>

struct sample
{
	unsigned int a : 3;
	unsigned int b : 3;
}s;

int main()
{
	s.a = 2;
	s.b = 6;

	printf("a: = %d  b: = %d\n", s.a, s.b);

	return 0;
}

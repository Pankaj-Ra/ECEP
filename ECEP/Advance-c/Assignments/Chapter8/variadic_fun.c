#include <stdio.h>
#include <stdarg.h>

int sum(int count, ...)
{
	va_list ap;
	int i, s = 0;
	va_start(ap, count);

	for (i = 0; i < count; i++)
	{
		s += va_arg(ap, int);
	}

	va_end(ap);

	return s;
}

int main()
{
	printf("%d\n", sum(2,10,20));
	printf("%d", sum(4,10,20,30,40));
}




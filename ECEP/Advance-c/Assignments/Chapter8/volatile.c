#include <stdio.h>

int main()
{
	volatile int flag = 0;
	while (flag != 1)
	{
		;
	}

	return 0;
}

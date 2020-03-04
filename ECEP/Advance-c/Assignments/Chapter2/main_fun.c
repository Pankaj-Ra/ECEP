#include <stdio.h>

int main()
{

	static int i = 10;
	if (i < 1)
	{
		return 0;
	}
	i--;
	printf("print i: = %d\n", i);
	main();

}

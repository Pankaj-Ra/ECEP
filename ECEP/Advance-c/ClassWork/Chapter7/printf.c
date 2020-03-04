#include <stdio.h>
#include <stdio_ext.h>

int main()
{
	char a[5];
	int i;
	for (i = 0; i < 5; i++)
	{
//		__fpurge(stdin);
		scanf("%c", a + i);
	}

	for (i = 0; i < 5; i++)
	{
		printf("%c", *(a + i));
	}
	printf("\n");
}

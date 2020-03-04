#include <stdio.h>
#include <string.h>

void my_puts1(char *str)
{
	while (*str != '\0')
	{
		putchar(*str);
		str++;
	}
	putchar('\n');
}

void my_puts2(char str[])
{
	int i = 0;
	while (str[i] != '\0')
	{
		putchar(str[i]);
		i++;
	}
}
int main()
{
	char mesh[] = "hello";
	char str[] = {'h','e','l','l','o','\0'};
	my_puts1(mesh);
	my_puts2(str);
	return 0;
}

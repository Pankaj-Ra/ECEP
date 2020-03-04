#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char string[100], temp1, *temp2;

	printf("Enter the string\n");
	scanf("%[^\n]%*c",string);

	char *ch = string;

	int i, j, len = strlen(string);

	i = len - 1;
	char *ptr = malloc(len * sizeof(char));

	ptr += i;
	while (i >= 0)
	{
		j = 0;
		if ((*ch != ' ') && (*ch != '\t') && (*ch != '\0'))
		{
			while ((*ch != ' ') && (*ch != '\t') && (*ch != '\0'))
			{
				*ptr = *ch;
				ch++;
				ptr--;
				i--;
				j++;
			}
			temp2 = ptr;
			ptr++;
			j -= 1;
			while ( j > 0)
			{
				temp1 = *ptr;
				*ptr = *(ptr + j);
				*(ptr + j) = temp1;
				ptr++;
				j--;
				j--;
			}
			ptr = temp2;
		}
		else if (*ch != '\0')
		{
			*ptr = *ch;
			ch++;
			ptr--;
			i--;
		}
	}
	ptr++;
	printf("String in reverse order:\n");
	for (i = 0; i < len; i++)
	{
		printf("%c",*(ptr + i));
	}

	return 0;
}








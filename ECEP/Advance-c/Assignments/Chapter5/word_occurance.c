#include <stdio.h>
#include <string.h>

int main()
{

	int i = 0;
	FILE *fs;
	char ch, *temp, path[50], word[10], *str;

	str = word;

	printf("Enter the file name or path\n");
	scanf("%s",path);
	printf("Enter the word\n");
	scanf("%s",word);

	fs = fopen(path, "r+");

	if (fs == NULL)
	{
		printf("fopen: failed to open the file\n");
		return -1;
	}
	temp = str;

	while ((ch = fgetc(fs)) && (ch != EOF))
	{
		if (ch == *str)
		{
		  while (ch == *str)
			{
				str += 1;
				ch = fgetc(fs);
				if ((ch == ' ') || (ch == '\n') || (ch == '\t') || (ch == EOF))
				{
					i++;
					str = temp;
					break;
				}
			}
		}
	}

	printf("The word (%s) occures %d times in the file\n", word, i);
	fclose(fs);

	return 0;
}




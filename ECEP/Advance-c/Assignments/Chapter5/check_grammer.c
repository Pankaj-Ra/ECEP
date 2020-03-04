#include <stdio.h>

int main()
{
	FILE *fs;
	char ch, path[50];

	printf("Enter the file name or path\n");
	scanf("%s",path);

	fs = fopen(path, "r+");

	if (fs == NULL)
	{
		printf("fopen: Failed to open file\n");
		return -1;
	}

	while ((ch = fgetc(fs)) && (ch != EOF))
	{
		if (ch == ',')
		{
			ch = fgetc(fs);
			if ((ch != ' ') || (ch != '\n'))
			{
				fseek(fs, -1, SEEK_CUR);
				if (ch == '\t')
				{
				fputc(' ', fs);
				}





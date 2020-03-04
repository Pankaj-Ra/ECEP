#include <stdio.h>
#include <string.h>

int main()
{
	int ch, i = 0;
	FILE *fs, *fd;
	char tok, path[50], buffer[100] = {'\0'}, *str;

	str = buffer;

	printf("Enter the tokken\n");
	scanf("%c",&tok);
	printf("ENter the file name or path\n");
	scanf("%s",path);

	fs = fopen(path, "r");

	if (fs == NULL)
	{
		printf("fopen: failed to open source file\n");
		return -1;
	}

	fd = fopen("dest.txt", "w");

	if (fd == NULL)
	{
		printf("fopen: Failed to open destination file\n");
		return -1;
	}

	while ((ch = fgetc(fs)) && (ch != EOF))
	{
		if (ch != tok)
		{
			fseek(fs, -1, SEEK_CUR);
			while (ch != EOF)
			{
				buffer[i] = ch;
				i++;
				ch = fgetc(fs);
				if (ch == tok)
				{
					buffer[i] = '\n';
					break;
				}
			}
			fputs(str, fd);
			fputs(str, stdout);
			while(i)
			{
				buffer[i] = '\0';
				i--;
			}
		}
	}

	fclose(fs);
	fclose(fd);

	return 0;
}





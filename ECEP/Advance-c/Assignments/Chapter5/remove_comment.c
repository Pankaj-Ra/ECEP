#include <stdio.h>

int main()
{
	//Declare the file poiter and variable
	FILE *fp;
	char ch, address[50];

	//Getting input from user
	printf("Enter the file name or path\n");
	scanf("%s",address);

	//open the file in the read mode
	fp = fopen(address, "r+");

	//Error handling
	if (fp == NULL)
	{
		printf("fopen: Failed\n");
		return -1;
	}

	//read byte by byte and delete all comment from source file
	while ((ch = fgetc(fp)) != EOF)
	{
		if (ch == '/')
		{
			ch = fgetc(fp);
			if (ch == '/')
			{
				fseek(fp, -2, SEEK_CUR);
				while (ch != '\n')
				{
					fputc(' ', fp);
					ch = fgetc(fp);
					fseek(fp, -1, SEEK_CUR);
				}
			}
			else if(ch == '*')
			{
				fseek(fp, -2, SEEK_CUR);
				fputc(' ', fp);
				while (ch)
				{
					if (ch != '\n')
					{
						fseek(fp, -1, SEEK_CUR);
						fputc(' ', fp);
					}
					ch = fgetc(fp);
					if (ch == '*')
					{
						ch = fgetc(fp);
						if (ch == '/')
						{
							fseek(fp, -2, SEEK_CUR);
							fputc(' ', fp);
							fputc(' ', fp);
							break;
						}
						fseek(fp, -1, SEEK_CUR);
					}
				}
			}
		}
	}

	return 0;
}





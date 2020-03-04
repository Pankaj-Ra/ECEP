#include <stdio.h>

int main()
{
	//Declare the file poiter and variable
	FILE *fp;
	char ch;

	//open the file in the read mode
	fp = fopen("Sample.txt", "r");

	//Error handling
	if (fp == NULL)
	{
		printf("fopen: Failed\n");
		return -1;
	}

	//read byte by byte + Display on the terminal
	while ((ch = fgetc(fp)) != EOF)
	{
		fputc(ch, stdout);
	}

	//close the file
	fclose(fp);
}

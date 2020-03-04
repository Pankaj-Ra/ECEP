#include <stdio.h>

int main()
{
	//Declare the file poiter and variable
	FILE *fp;
	char ch, address[50];
	int i = 0, j = 0, k = 0;

	//Getting input from user
	printf("Enter the file name or path\n");
	scanf("%s",address);

	//open the file in the read mode
	fp = fopen(address, "r");

	//Error handling
	if (fp == NULL)
	{
		printf("fopen: Failed\n");
		return -1;
	}

	//read byte by byte + Display word count 
	while ((ch = fgetc(fp)) != EOF)
	{
		i++;
		if((ch == ' ') || (ch == '\n'))
		{
			j++;
		}
		if(ch == '\n')
		{
			k++;
		}
	}
	printf("character count: %d\n", i);
	printf("Word count: \t%d\n", j);
	printf("Line count: \t%d\n", k);

	fclose(fp);

	return 0;
}



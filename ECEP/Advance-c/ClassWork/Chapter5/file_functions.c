#include <stdio.h>

int main()
{
	//Declare the file pointer
	FILE *fp;

	//Open the file in read mode
	fp = fopen("Sample.txt", "r");

	//Check for error
	if (fp == NULL)
	{
		printf("Failed: fopen\n");
		return -1;
	}

	//Print the character pointed by fp
	printf("Char: %c\n", fgetc(fp));

	//Print the position
	printf("Pos: %ld\n", ftell(fp));

	//Demo of fseek
	fseek(fp, -3, SEEK_END);
	printf("Pos: %ld\n", ftell(fp));
	printf("Char: %c\n",fgetc(fp));

	return 0;

}



#include <stdio.h>
#define MAX 80

int main()
{
	//Declare the file pointer
	FILE *fs;

	//Declare the buffer of Max len 80
	char buff[80] = {'\0'};

	//open the file in the read mode
	fs = fopen("Sample.txt", "r");

	//Error handling
	if (fs == NULL)
	{
		printf("fopen: Failed\n");
		return -1;
	}

	//Open the dest. file in write mode
	FILE *fd = fopen("dest.txt", "a");

	//Check for error
	if (fd == NULL)
	{
		printf("fopen: Failed for dst.txt\n");
			return -1;
	}

	//Read byte by byte and display on the terminal
	while ((fgets(buff, MAX, fs)) != NULL)
	{
		fputs(buff, fd);
	//	fputs(buff, stdout);
	}

	//Close all file
	fclose(fs);
	fclose(fd);

	return 0;

}

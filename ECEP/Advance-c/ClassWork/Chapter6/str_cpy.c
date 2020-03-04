#include <stdio.h>
#include <string.h>

//declaring function to copy the string
void my_strcpy(char *stc, char *dst);
void my_strcpy(char *stc, char *dst)
{

	while (*dst++ = *stc++);
}

int main()
{
	//Declare source string and destination string
	char source[100], destination[100] = {'\0'};

	//Enter the string as input
	printf("Enter the string\n");
	scanf("%[^\n]",source);

	//calling function
	my_strcpy(source, destination);

	//Print the string
	printf("New String: \n%s\n",destination);

	return 0;
}




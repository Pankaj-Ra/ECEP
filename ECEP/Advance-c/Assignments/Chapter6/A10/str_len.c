											/* Findout length of the string */
#include <stdio.h>

//Function to findout the length of the string passing  address to pointer as a parameter
int string_length(char *str);
int string_length(char *str)
{
	int i = 0;

	while (*str)
	{
		str++;
		i++;
	}
	return(i);
}
int main()
{
	//Declare a string
	char string[100];

	printf("Enter the string\n");
	scanf("%[^\n]",string);

	//Calling function and print length of the string
	printf("Length of the String is = %d",string_length(string));

	return 0;
}

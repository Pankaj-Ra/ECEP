/*Implement strstr() Function*/
#include <stdio.h>
#include <string.h>

//Function is used to find out the substring of main string
char *substring(char *str1, char *str2);
char *substring(char *str1, char *str2)
{
	//Declare the variables
	int temp, i = 0;
	//Find string length
	temp = strlen(str2);
	while (*str1)
	{
		if (*str1 == *str2)
		{
			//until condition satisfies increment both pointer
			while (*str1 == *str2 && *str2 != '\0')
			{
				str1++;
				str2++;
				i++;
			}
			//when string 2 counter NULL point to the starting address
			if (*str2 == '\0')
			{
				str1 -= temp;
				return(str1);
			}
			str2 -= i;
			continue;
		}
		str1++;
	}
	return (NULL);
}
int main()
{
	//Declare string, pointer and type
	char a1[100], a2[100], *out;
	printf("Enter the first string \n");
	scanf("%[^\n]%*c",a1);
	printf("Enter the second string \n");
	scanf("%[^\n]%*c",a2);

	//Call the function
	out = substring(a1, a2);

	//if function return char value other than NULL
	if(out != NULL)
	{
		printf("Found Substring:\n");
		puts(out);
	}

	//if function return NULL
	if(out == NULL)
		printf("\nNot a Substring:");

	return 0;
}





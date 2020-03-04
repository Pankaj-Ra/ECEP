									/* Implement function to generate tokken */
#include <stdio.h>
#include <string.h>

//this function takes string and delimiter as parameters in form of pointers
char *string_tokken(char *str1, char *str2)
{
	//Declaring static char pointer to keep  values intact 
	static char *temp1, *temp2;
	char *pos;

	//checking condition that pointer holds NULL value or not
	if (str1 != NULL)
	{
		pos = str1;
	}
	else
	{
		pos = temp2;
	}

	//checking for NULL condition
	if (pos != NULL)
	{
		temp1 = pos; 
		while (*pos)
		{
			//while loop will run until pointer points to NULL char or both pointer holds same value
			if (*pos == *str2)
			{
				//storing address of next char in pointer temp2 to be used for next func call
				temp2 = pos + 1;
				*pos = '\0';
				return temp1;
			}
			pos++;
		}
		temp2 = NULL;
		return temp1;
	}
	return NULL;
}

int main()
{
    //declaring string delimiter and pointer
	char a1[100], delim, *ptr;

	printf("Enter the string\n");
	scanf("%[^\n]%*c",a1);
	printf("\nEnter the delimeter\n");
	scanf("%c",&delim);

	//calling function
	ptr = string_tokken(a1, &delim);

	//Call function again until it returns NULL value
	while(ptr != NULL)
	{
		printf("\n%s",ptr);
		//passing NULL instead of string to start pointer after '\0'
		ptr = string_tokken(NULL, &delim);
	}
	printf("\n");

	return 0;
}


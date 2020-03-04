/*  implement squeeze operation on a string  */
#include <stdio.h>

void squeeze_space(char *str)
{
	char *temp;

	while (*str)
	{
		while (*str == ' ')
		{
			temp = str;
			str++;
			if (*str == ' ')
			{
				while (*str)
				{
					*str = *(str + 1);
					str++;
				}
				str = temp;
			}
		}
		str++;
	}
}

//Function is used to squeeze the first string by eliminating all char of second string present in it
void do_squeeze(char *str1, char *str2)
{
	//Declaring temp variable and pointers
	char *temp1, *temp2;

	//storing initialo position of string pointer in temp pointer
	temp1 = str1;
	while (*str1)
	{
		while (*str1)
		{
			//thhis loop run when value in both pointers are equal
			while ((*str1 == *str2) && (*str1 != ' '))
			{
				//storing current position of string pointer
				temp2 = str1;
				//this loop is used to eliminate the matching value and shift the string 1 step back
				while (*str1)
				{
					*str1 = *(str1 + 1);
					str1++;
				}
				str1 = temp2;
			}
			str1++;
		}
		//Incrimenting second string pointer and reseting first pointer to initial position
		if (*str2)
		{
			str2++;
			str1 = temp1;
		}
	}
}

int main()
{
	//Declaring 2 strings
	char a1[100], a2[100];

	printf("\nEnter the first string\n");
	scanf("%[^\n]%*c",a1);
	printf("Enter the second string\n");
	scanf("%[^\n]%*c",a2);

	//calling function and print the resultant string 
	squeeze_space(a1);
	do_squeeze(a1, a2);
	printf("String after squeeze: \n%s\n ",a1);

	return 0;
}



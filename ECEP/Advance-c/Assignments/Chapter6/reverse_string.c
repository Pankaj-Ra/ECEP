								/* Implement a function to Reverse the string */
#include <stdio.h>

//Function is use to reverse the elements of the string
void reverse_string(char *str)
{
	//declare intiger and character variables
	int i = 0;
	char temp1;

	//loop is used to findout the length of the string
	while(*str)
	{
		str++;
		i++;
	}
	str -= i;
	i -= 1;
	//length of string is stored in variable i and loop runs until value of i > 0
	while(i > 0)
	{
		//Value of pointer is stored in temperary variable to reverse the string
		temp1 = *str;
		*str = *(str + i);
		str += i;
		*str = temp1;
		str -= i;
		str++;
		--i;
		--i;
	}
}

//Recursive Function is use to reverse the string
void recursive_reverse(char *str)
{
	//Terminating condition
	if (*str == '\0')
	{
		return;
	}
        //calling function until Null position
        recursive_reverse(str + 1);
        printf("%c", *str);
}

int main()
{
	//Declaring string
	char array[100];

	printf("Enter the string\n");
	scanf("%[^\n]",array);
	printf("\nOriginal String  := %s", array);

	//calling recursive function and pasing string
	printf("\nUsing recurtion  := ");
	recursive_reverse(array);

	//Calling function and passing string address
	reverse_string(array);
	printf("\nWithout recurtion:= %s\n", array);


	return 0;
}




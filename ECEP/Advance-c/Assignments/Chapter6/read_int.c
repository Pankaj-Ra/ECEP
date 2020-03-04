							/* Function read_int to read an integer */
#include <stdio.h>

//Function is use to read string as input and convert ascii to integer
int read_int(const char *s)
{
	//Initialising variable
	int sum = 0;

	while(*s)
	{
		//find ascii value of char and convert into integer by adding them all
		sum = sum * 10 + (*s - 48);
		s++;
	}
	//return sum as intiger value
	return(sum);
}
int main()
{
	//Declare string and type
	char string[100];

	printf("Enter the string\n");
	scanf("%s",string);

	//calling function and print output
	printf("Print integer: \n%d",read_int(string));

	return 0;
}


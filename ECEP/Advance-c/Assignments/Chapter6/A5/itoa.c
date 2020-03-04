						/*implement function which read integer as input and give string as output using itoa*/
#include <stdio.h>

//Function is used to convert intiger value and return corresponding ascii values
void int_ascii(int n, char *s)
{
	//Declare variables
	int i = 0, temp, rem;

	temp = n;
	//this loop is use to find out the number of integer values
	while(temp > 0)
	{
		temp = temp / 10;
		i++;
	}
	//put '\0' at the end of the string for termination
	s += i;
	*s = '\0';
	s -= 1;
	//this loop is used to take one intiger value at a time, find out ascii equivalent and store in string
	while(n > 0)
	{
		rem = n % 10;
		n = n / 10;
		*s = rem + 48;
		s--;
	}
}
int main()
{
	//Declare string and intiger variable
	int num;
	char string[100];
	printf("Enter the number\n");
	scanf("%d",&num);

	//calling function(passing addres of string and number) and printing output
	int_ascii(num, string);
	printf("Integer to ASCII is: \n%s",string);

	return 0;
}






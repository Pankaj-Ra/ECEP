		      /*Implement function which read string as input and print integer using acii to int conversion */
#include <stdio.h>

//Function is use to read string as input and convert ascii to integer
int ascii_int(const char *s);
int ascii_int(const char *s)
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
	//Declare array and type
	char array[100];

	printf("Enter the string\n");
	scanf("%[^\n]%*c",array);

	//calling function and print output
	printf("Ascii to integer: \n%d",ascii_int(array));

	return 0;
}



	 
	




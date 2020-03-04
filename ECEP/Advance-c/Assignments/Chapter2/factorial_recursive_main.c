									/* Find Factorial using only main function*/
#include <stdio.h>

//Globally declaring variable
int factorial = 1;

int main()
{
	//Declaring static variable so that memory assigned to it remain intact 
	static int num;

	//Using this condition to get input from user only once in start
	if (factorial == 1)
	{
	printf("Enter the Number\n");
	scanf("%d", &num);
	}

	//Exit condition
	if (num == 0)
	{
		printf("Factorial: = %d", factorial);

		return 0;
	}

	factorial *= num;
	num -= 1;

	//Recursive call to main func.
	main();
}





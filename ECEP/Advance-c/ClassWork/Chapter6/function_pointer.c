						/* Demo: To show how to call a function pointer */
#include <stdio.h>

int add(int a, int b)
{
	return a + b;
}

int main()
{
   
   	//Declare the function pointer
   	//Syntax
   	//return_type(*fun_pointer)(parameter_list);

   	int (*fp)(int, int);

   	//nit the function. pointer
   	fp = add;

   	//Calling the functiion ad through the function pointer
   	int res = (*fp)(10,2);

   	//Print the result
   	printf("Res: %d\n", res);

   	return 0;
}

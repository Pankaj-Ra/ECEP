#include "stack.h"

int main()
{
	char data, infix[MAX] = {'\0'};
	char *postfix;
	int size, result;

	printf("Enter the infix expression\n");
	scanf("%[^\n]", infix);
        
	size = strlen(infix);
        
	postfix = infix_to_postfix(infix, size);

	printf("Postfix expression:\n%s\n", postfix);
       
	size = strlen(postfix);
	
	result = evaluate_postfix(postfix, size);

	printf ("Result = %d\n", result);

	return 0;
}



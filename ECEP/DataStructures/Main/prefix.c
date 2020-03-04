#include "stack.h"

int main()
{
	char data, infix[MAX] = {'\0'};
	char *prefix;
	int size, result;

	printf("Enter the infix expression\n");
	scanf("%[^\n]", infix);

	size = strlen(infix);

	prefix = infix_to_prefix(infix, size);

	printf("Prefix expression:\n%s\n", prefix);

	size = strlen(prefix);

	result = evaluate_prefix(prefix, size);

	printf("Result = %d\n", result);

	return 0;
}


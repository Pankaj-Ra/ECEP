#include <stdio.h>

int main()
{
	int i, temp = 0;
	char cha = 'a', new = NULL;
	unsigned int mask;

/*	for (i = 7; i >= 0; i--)
	{
		ch &= (cha >> i);
	        temp &= (ch << i);
		ch = 1;
	}
	*/
        temp |= cha;
	for (mask = 1 << (8 - 1); mask; mask >>=1)
	{
		temp & mask? printf("1"): printf("0");
	}
        printf("\n");

	new |= temp;
	printf("new: %c\n", new);

	for (mask = 1 << (8 - 1); mask; mask >>=1)
	{
		temp & mask? printf("1"): printf("0");
	}

        printf("\n");
	new = '\0';
	printf("new: %c\n", new);
        temp = 0;
        temp |= new;
	for (mask = 1 << (8 - 1); mask; mask >>=1)
	{
		temp & mask? printf("1"): printf("0");
	}
        printf("\n");

	return 0;
}



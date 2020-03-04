#include<stdio.h>
int main()
{
	int opt1,opt2,ADD,MUL,SUB,DIV,MOD;
	char optr;
	printf ("Enter the Expression\n");
	scanf ("%d",&opt1);
	getchar();
	scanf ("%c",&optr);
	scanf ("%d",&opt2);
	switch (optr)
	{
		case '+':
			ADD=opt1 + opt2;
			printf ("SUM: %d\t",ADD);
			break;
		case '-':
			SUB=opt1 - opt2;
			printf ("DIFFERENCE: %d\t",SUB);
			break;
		case '*':
			MUL=opt1 * opt2;
			printf ("MULTIPLICATION: %d\t",MUL);
			break;
		case '/':
			DIV=opt1 / opt2;
			printf ("DIVISION: %d\t",DIV);
			break;
		case '%':
			MOD=opt1 % opt2;
			printf ("MODULUS: %d\t",MOD);
			break;
	}
	printf ("\n");
}


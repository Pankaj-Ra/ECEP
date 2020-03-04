#include <stdio.h>
int main()
{
	int NUM1, NUM2, REM, QUOT;

	printf ("Enter the First No\n");
	scanf ("%d",&NUM1);
	printf ("Enter the second No\n");
	scanf ("%d",&NUM2);
	QUOT = NUM1 / NUM2;
	REM = NUM1 % NUM2;
	printf ("Quotient = %d\t Remender = %d\t\n",QUOT, REM);

	return 0;
}

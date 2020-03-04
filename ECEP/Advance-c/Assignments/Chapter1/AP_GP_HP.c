#include <stdio.h>
int main()
{
	int a, i, r, n, STORE, TOTAL = 0;

	double R, HP = 0.0;
	printf ("Enter the Range of Series\n");
	scanf ("%d",&n);
	printf ("Enter first value\n");
	scanf ("%d",&a);
	printf ("Enter the difference\n");
	scanf ("%d",&r);
	printf ("Arithmatic Progression\n");
	STORE = a;
	for (i = 0; i < n; i++)								//by using for loop and adding first variable & diff. we get A.P.
	{
		TOTAL = a + r;
		printf ("%d\t",a);
		a = TOTAL;
	}
	printf ("\nGeomatric Progression\n");
	a = STORE;
	for (i = 0; i < n; i++)
	{
		TOTAL = a * r;										//G.P. is multiplication of first value and the diff given.
		printf ("%d\t",a);
		a = TOTAL;
	}
	printf ("\nHarmonic progression\n");
	a = STORE;
	R = 1.0/a;
	for (i = 0; i < n; i++)										//H.P. is addition of inverse of A.P. series
	{
		HP = R + r;
		printf ("%f\t",R);
		R = HP;
	}
	printf ("\n");

	return 0;
}









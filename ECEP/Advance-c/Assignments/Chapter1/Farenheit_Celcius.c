#include<stdio.h>
main()
{
	int F;
	float C=0;
	printf ("Enter the temperature value in farenheit\n");
	scanf ("%d",&F);
	C = (5.0/9.0)*(F - 32);
	printf ("Temperature in Celcius is :%f\t",C);
	printf ("\n");
}




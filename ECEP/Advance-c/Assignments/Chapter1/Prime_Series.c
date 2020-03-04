#include<stdio.h>
#include<math.h>
int main()
{
	int N, i, j=2, REMENDER=1, COUNT;
START: printf ("Enter the number N\n");
		 scanf ("%d",&N);
		 if (N<2)
		 {
			 printf ("Enter the valid input > 2 \n");
			 goto START;
		 }
		 for (i=2;i<=N;i++)
		 {
			 j=2;
			 COUNT=sqrt(i); 
			 while (j <= COUNT)
			 {
				 REMENDER = (i % j);
				 if (REMENDER == 0)
				 {
					 break;
				 }
				 j++;
			 }
			 if (REMENDER !=0)
			 {
			 printf ("%d\t",i);
			 }
		 }
		 printf ("\n");
		 return 0;
}



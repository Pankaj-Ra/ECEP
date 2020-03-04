#include<stdio.h>
int palindrome(int num, int size)
{
	int new = 0, rem = 0, i;
	while (num > 0)
	{
	//for (i = 0;i < size;i++)
	{
		rem = (num % 10);
		new = new * 10 + rem;
		num = num/10;
	}
	}
	return (new);
}
main()
{
	int num, size, i, rem, new;
//	printf ("Enter the Size\n");
//	scanf ("%d",&size);
	printf ("Enter the number\n");
	scanf ("%d",&num);
	new = palindrome(num, size);
	printf ("%d\n",new);
	if (new == num)
	{
		printf ("It's Palindrome\n");
	}
	else
	{
		printf ("It's not a Palindrome\n");
	}
}






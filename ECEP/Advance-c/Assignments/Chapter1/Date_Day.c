#include<stdio.h>
int main()
{
	int DAY, i, ADD;
	printf ("Enter Date\n");
	scanf ("%d",&DAY);
	if (DAY == 1)
	{
		printf ("MONDAY\n");
	}
	if (DAY == 2)
	{
		printf ("TUESDAY\n");
	}
	if (DAY == 3)
	{
		printf ("WEDNESDAY\n");
	}
	if (DAY == 4)
	{
		printf ("THURSDAY\n");
	}
	if (DAY == 5)
	{
		printf ("FRIDAY\n");
	}
	if (DAY == 6)
	{
		printf ("SATURDAY\n");
	}
	if (DAY == 7)
	{
		printf ("SUNDAY\n");
	}
	i = 1;
	ADD =1;
	while (i <= 365)
	{
		ADD = ADD +7;
		if (ADD == DAY)
		{
			printf ("MONDAY\n");
		}
		i++;
	}
	i = 1;
	ADD =2;
	while (i <= 365)
	{
		ADD = ADD +7;
		if (ADD == DAY)
		{
			printf ("TUESDAY\n");
		}
		i++;
	}
	i = 1;
	ADD =3;
	while (i <= 365)
	{
		ADD = ADD +7;
		if (ADD == DAY)
		{
			printf ("WEDNESDAY\n");
		}
		i++;
	}
	i = 1;
	ADD =4;
	while (i <= 365)
	{
		ADD = ADD +7;
		if (ADD == DAY)
		{
			printf ("THURSDAY\n");
		}
		i++;
	}
	i = 1;
	ADD =5;
	while (i <= 365)
	{
		ADD = ADD +7;
		if (ADD == DAY)
		{
			printf ("FRIDAY\n");
		}
		i++;
	}
	i = 1;
	ADD =6;
	while (i <= 365)
	{
		ADD = ADD +7;
		if (ADD == DAY)
		{
			printf ("SATURDAY\n");
		}
		i++;
	}
	i = 1;
	ADD =7;
	while (i <= 365)
	{
		ADD = ADD +7;
		if (ADD == DAY)
		{
			printf ("SUNDAY\n");
		}
		 i++;
	 }
}










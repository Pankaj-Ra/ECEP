					/* Read n & n person name and sort and print the names*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function is use to allocate memory and populate names
void alloc_popul_mem(char ***p, int n)
{
	int i;
	int len;
	char string[32];

        //Allocating memory fragments equal to no of names
	*p = malloc(n * sizeof(int *));
 
        //Allocating memory location according to size of names and populate
	for (i = 0; i < n; i++)
	{
		printf("Enter the name max len 32: %d\t", i);
		scanf("%[^\n]%*c", string);
		len = strlen(string);
		(*p)[i] = malloc((len + 1) * sizeof(char));
		strcpy((*p)[i], string);
	}
}

//Function is use to sort the names Alphabatically
void sorting_names(char **p, int n)
{
	int i, j, k;
	char *temp;

        //Sorting names alphabtically and swapping address
	for (j = n - 1; j >= 0; j--)
	{
		for (i = 0; i < j; i++)
		{
			k = 0;
			while (p[i][k] == p[i + 1][k])
			{
				k++;
			}
			if (p[i][k] > p[i + 1][k])
			{
				temp = p[i];
				p[i] = p[i + 1];
				p[i + 1] = temp;
			}
		}
	}
}

int main()
{
	//Declaring variables and pointer
	char **p;
	int i,n;

        //Getting input from the user
	printf("ENter the number of names\n");
	scanf("%d", &n);
	__fpurge(stdin);

        //calling function to allocate memory
	alloc_popul_mem(&p, n);

        //printing names stored the the memory locations
	printf("\n[Populating rows:]\n");
	for (i = 0; i < n; i++)
	{
		printf("Name: %d\t", i);
		puts(*(p + i));
		printf("\n");
	}

        //calling function to sort names
	sorting_names(p, n);

        //printing names in sorted order
	printf("\n[Sorted names:]\n");
	for (i = 0; i < n; i++)
	{
		printf("Name: %d\t", i);
		puts(*(p + i));
		printf("\n");
	}

	return 0;
}

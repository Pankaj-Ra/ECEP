#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
	char *name;
	float marks[3];
	float average;
	char grade;
}student_t;

void allocate_memory(student_t ***p, int n)
{
	//Allocate the memory for the array
	*p = calloc(n, sizeof(student_t *));

	//Allocate the memory for all the students
	int i;
	for (i = 0; i < n; i++)
    {
    	(*p)[i] = calloc(1, sizeof(student_t));
	}
}

void read_input(student_t ***p, int n)
{
	int i;
	//Declare local buffer to store name temporarily
	char buffer[20];

	//Read the input from the user for all the students
	for (i = 0; i < n; i++)
	{
		//Prompt the user to enter the name + Collect it in the local buffer
		printf("Enter the name for %d student\n", i);
		scanf("%s", buffer);

		//Find the length to allocate the memory dynamically
		int len = strlen(buffer);

		//Allocate the memory depending upon the length of the name
		(*p)[i]->name = calloc(len + 1, sizeof(char));

		//Copy the name from buffer to newly allocated memory
		strcpy((*p)[i]->name, buffer);

		//Clear the buffer using the memset function
		memset(buffer, '\0', 20);

		//Read the marks of 3 subjects
		printf("Enter the marks of 3 subjects\n");
		int j;
		for (j = 0; j < 3; j++)
		{
			scanf("%f", &((*p)[i]->marks[j]));
		}
	}
}

void print_info(student_t **p, int n)
{
	int i, j;

	//Printing the input read from the user for all students
	for (i = 0; i < n; i++)
	{
		printf("Detail of %d student\n", i);

		printf("name: %s\n", p[i]->name);

		//Read the marks of 3 subjects
		printf("Marks of 3 subjects\n");
		int j;
		for (j = 0; j< 3; j++)
		{
			printf("Marks[%d]: %f\n", j, p[i]->marks[j]);
		}

		printf("Average[%d]: %f\n", i, p[i]->average);
	}
}

void find_average(student_t **p, int n)
{
	int i, j;

	for (i = 0; i < n; i++)
	{
		p[i]->average = 0;
		for (j = 0; j < 3; j++)
		{
			p[i]->average += p[i]->marks[j];
		}

		p[i]->average /= 3;

	}
}

int main()
{
	//Declare the pointer to pointer variable of type student_t
	student_t **p;
	int n;

	//Read the number of students
	printf("Enter the no of students\n");
	scanf("%d", &n);

	//Call the function to allocate the memory
	allocate_memory(&p, n);

	read_input(&p, n);

	find_average(p, n);

	print_info(p, n);

	return 0;
}




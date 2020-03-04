#include <stdio.h>
#include <string.h>

//Define structure globally
typedef struct employee
{
	char name[20];
	int age;
	char gender;
	short id;
	float salary;
}EMP;

int main()
{
	//Define variable using alias
	int i;
	EMP e[2];

	for (i = 0; i < 2; i++)
	{
		//Read the input from the user
		printf("Enter the name, age, id, salary, gender for %d employee\n", i + 1);
		scanf("%s%d%hd%f", e[i].name, &e[i].age, &e[i].id, &e[i].salary);
		__fpurge(stdin);
		scanf("%c", &e[i].gender);
	}

	for (i = 0; i < 2; i++)
	{
		printf("\nName: %s\nAge: %d\nGender: %c\nID: %d\nSalary: %f\n", e[i].name, e[i].age, e[i].gender, e[i].id, e[i].salary);
	}

	return 0;
}

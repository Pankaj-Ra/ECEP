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

void print(EMP e1)
{
	//printing the structure member values
	printf("Name: %s\nAge: %d\nGender: %c\nID: %d\nSalary: %f\n", e1.name, e1.age, e1.gender, e1.id, e1.salary);
}

int main()
{
	//Declare the structure variable + Init = Definition
	EMP e1 = { "Ravi", 26, 'M', 12345, 30};

	print(e1);

	return 0;
}



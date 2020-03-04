//Demo-1: Usage of structures

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
	//Declare the structure variable
	struct employee e1 = {"Ravi", 26, 'M', 12345, 30};

	//Declaring the variable using alias
	EMP e2;

	//Init members
//	e2.name = "Manoj";
	strcpy(e2.name, "MrBond");
	e2.age = 28;
	e2.gender = 'M';
	e2.id = 7;
	e2.salary = 12.23;

	//Declare the pointer + Init
	EMP *p = &e2;

	//Printing the structure member values
	printf("Name: %s\nAge: %d\nGender: %c\nID: %d\nSalary: %f\n", e1.name, e1.age, e1.gender, e1.id, e1.salary);

	printf("\nName: %s\nAge: %d\nGender: %c\nID: %d\nSalary: %f\n", e2.name, e2.age, e2.gender, e2.id, e2.salary);

	//Printing using the pointer
	printf("\nName: %s\nAge: %d\nGender: %c\nID: %d\nSalary: %f\n", p->name, p->age, p->gender, p->id, p->salary);
#if 0	
	//Declare the variable
	EMP e3;

	//Read Input from user
	printf("\nEnter name, age, ID, salary, gender\n");
	scanf("%s%d",e3.name, &e3.age);
	scanf("%d%f", &e3.id, &e3.salary);
	__fpurge(stdin);
	scanf("%c", &e3.gender);

	printf("Name: %s\nAge: %d\nGender: %c\nID: %d\nSalary: %f\n", e3.name, e3.age, e3.gender, e3.id, e3.salary);
#endif
	return 0;
}

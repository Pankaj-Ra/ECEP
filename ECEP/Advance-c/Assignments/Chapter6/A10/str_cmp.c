							/* Comapring two strings "Case sensitive" & "Case Insensitive" */
#include <stdio.h>

//Function to compare two strings case sensitive
int cmp_str(char *str1, char *str2);
int cmp_str(char *str1, char *str2)
{
	//Until both pointers hold same value increment pointers
	while (*str1 == *str2 && *str1 != '\0')
	{
		str1++;
		str2++;
	}

	//when both pointers counter NULL char return 0 
	if ((*str1 == '\0') && (*str2 == '\0'))
		return 0;

	//when pointers dont hold same value return 1
	if (*str1 != *str2)
		return 1;
}

//Function use to compare two string irrespective of case
int case_cmp_str(char *str1, char *str2);
int case_cmp_str(char *str1, char *str2)
{
	//Until both pointers are same OR eqivalent to its upper case, increment the pointers 
	while ((*str1 == *str2 || *str1 == (*str2 + 32) || *str2 == (*str1 + 32)) && *str1 != '\0')
	{
		str1++;
		str2++;
	}

	//when both pointers counter NULL char return 0
	if (*str1 == '\0' && *str2 == '\0')
		return 0;

	//when pointers dont holds same value return 1
	if (*str1 != *str2)
		return 1;
}
int main()
{
	//Declare strings and intiger varaiable
	int oput;
	char a1[100], a2[100];

	printf("Enter the first string\n");
	scanf("%[^\n]%*c",a1);
	printf("Enter the second string\n");
	scanf("%[^\n]%*c",a2);

	//Calling the function
	oput = cmp_str(a1, a2);

	//print result depents upon value returned by the function
	if(oput == 0)
		printf("(CASE SENSTIVE):= Strings are same\n");
	if(oput == 1)
		printf("(CASE SENSTIVE):= Strings are not same\n");

	//Calling function
	oput = case_cmp_str(a1, a2);

	//print result depends upon value returned by the function
	if(oput == 0)
		printf("(CASE INSENSTIVE):= Strings are same\n");
	if(oput == 1)
		printf("(CASE INSENSTIVE):= Strings are not same\n");

	return 0;
}





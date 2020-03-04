#include<stdio.h>
#include <string.h>
int main()
{
	char str[10] = "hello", *mesg = "hello";

//	mesg[2] = "d";
	printf("size of str \t %lu\n",sizeof(str)); 
	printf("length of str \t %d\n",strlen(str)); 
	printf("size of hello \t %lu\n",sizeof("hello")); 
	printf("size of mesg \t %lu\n",sizeof(mesg)); 
	printf("length of mesg  %d\n",strlen(mesg)); 
	 
	return 0;
}


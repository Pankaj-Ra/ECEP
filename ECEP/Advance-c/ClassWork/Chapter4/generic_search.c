#include <stdio.h>
#include <stdlib.h>
#define EQUAL 1
#define NOT_EQUAL -1

int generic_search(void *ap, void *var, int arr_len, int size)
{
	int check, i = 0;

	while (arr_len--)
	{
		check = comapre(ap, var, size);
		if(check == 1)
			return i;
		ap += size;
		i++;
	}
	if (check == -1)
		return -1;
}

int comapre(void *p, void *q, int size)
{
	while ((*(char *)p == *(char *)q) && size--)
	{
		p += sizeof(char);
		q += sizeof(char);
	}
	if (size == 0)
		return EQUAL;
	return NOT_EQUAL;
}

int main()
{
	int a[] = {1,2,3,4,5,6,7,8,9}, b = 6;

	int index = generic_search(a, &b, sizeof(a)/sizeof(int), sizeof(int));

	if (index >= 0)
		printf("Given variable: %d\t is found at position: %d\n", b, index);
	else if (index == -1)
		printf("Can't find given variable: %d\n", b);

	float c[]= {1.1,1.2,1.3,1.4,1.5}, f = 1.3;

	index = generic_search(c, &f, sizeof(c)/sizeof(float), sizeof(float));

	if (index >= 0)
		printf("Given variable: %f is found at position: %d\n", f, index);
	else if (index == -1)
		printf("Can't find given variable: %f\n", f);

	return 0;
}





#include "stack.h"

int main()
{
	int size, key, index;
	int i;

	printf("Enter the size of the array\n");
	scanf("%d", &size);

	int *array = malloc(size * sizeof(int));
	printf("Enter the values\n");
        
	for (i = 0; i < size; i++)
	{
		scanf("%d", &array[i]);
	}

	printf("Enter the value you want to search\n");
	scanf("%d", &key);

	index = binary_search(array, size, key);

	if (index == DATA_NOT_FOUND)
	{
		printf ("Given data is not found\n");
	}
	else
	{
		printf("Data is present at the index pos: %d\n", index);
	}

	return 0;
}





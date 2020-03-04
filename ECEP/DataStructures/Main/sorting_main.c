#include "sorting.h"

int main()
{
	int i, size, option;

	printf("Enter the size of the array\n");
	scanf("%d", &size);

	data_t array[size];

	printf("Enter thye values\n");

	for (i = 0; i < size; i++)
	{
		scanf("%d", &array[i]);
	}
        
	start:
	printf("Select the sorting method:\n 1. Bubble sort\n 2. Insertion sort\n 3. Selection sort\n 4. Merge sort\n 5. Quik sort\n 6.Exit\n");
	scanf("%d", &option);

	switch (option)
	{
		case 1:

			bubble_sort(array, size);
			print_array(array, size);

			break;

		case 2:

			insertion_sort(array, size);
			print_array(array, size);

			break;

		case 3:

			selection_sort(array, size);
			print_array(array, size);

			break;

		case 4:

			merge_sort(array, size);
			print_array(array, size);

			break;

		case 5:

			quick_sort(array, 0, size - 1);
			print_array(array, size);

			break;

		case 6:

			printf("EXIT\n");

			break;

		default :

			printf("Select the option between 1 to 5\n");

			goto start;

			break;
	}

	return 0;
}

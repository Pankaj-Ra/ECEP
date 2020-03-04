#include "../Include/sorting.h"

void bubble_sort(data_t array[], int size)
{

	int i, j, temp = 0;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + i])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

void insertion_sort(data_t array[], int size)
{

	int i , j, key;

	for (i = 1; i < size; i++)
	{
		key = array[i];
		for (j = i - 1; (j >= 0) && (key < array[j]); j--)
		{
			array[j + 1] = array[j];
		}
		array[j + 1] = key;
	}
}

void selection_sort(data_t array[], int size)
{

	int i , j, min, temp;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[min] > array[j])
			{
				min = j;
			}
		}
		if (i != min)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
		}
	}
}

void merge_sort(data_t array[], int size)
{

	int i, mid;

	if (size == 1)
	{
		return;
	}

	mid = size / 2;

	data_t *left = malloc((size - mid) * sizeof(data_t));
	data_t *right = malloc(mid * sizeof(data_t));

	for (i = 0; i < size - mid; i++)
	{
		left[i] = array[i];
	}

	for (i = (size - mid); i < size; i++)
	{
		right[i - (size - mid)] = array[i];
	}

	merge_sort(left, (size - mid));

	merge_sort(right, mid);

	merge(array, left, right, (size - mid), mid);

}

void merge(data_t array[], data_t left[], data_t right[], int Lsize, int Rsize)
{
	int i = 0, j = 0, k = 0;

	while ((i < Lsize) && (j < Rsize))
	{
		if (left[i] < right[j])
		{
			array[k] = left[i];
			k++;
			i++;
		}
		else
		{
			array[k] = right[j];
			k++;
			j++;
		}
	}

	while (i != Lsize)
	{
		array[k] = left[i];
		k++;
		i++;
	}

	while (j != Rsize)
	{
		array[k] = right[j];
		k++;
		j++;
	}

}

void quick_sort(data_t array[], int start, int end)
{
	int loc;
	if (start >= end)
	{
		return;
	}

	loc = partition(array, start, end);
	quick_sort(array, start, loc - 1);
	quick_sort(array, loc + 1, end);
}

int partition(data_t array[], int start, int end)
{
	int pivot;
	int i, j, temp;

	pivot = array[start];
	i = start + 1;
	j = end;

	Start:

	while ((array[i] < pivot) && (i <= end))
	{
		i++;
	}

	while (array[j] > pivot)
	{
		j--;
	}

	if (i < j)
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		i++;
		j--;
		goto Start;
	}
	else
	{
		array[start] = array[j];
		array[j] = pivot;
		return j;
	}
}

void print_array(data_t array[], int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		printf("%d\t", array[i]);
	}
	printf("\n");

}



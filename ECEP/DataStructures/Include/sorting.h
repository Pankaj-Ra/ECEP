#ifndef _SORTING_H_
#define _SORTING_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int data_t;

void bubble_sort(data_t array[], int size);
void insertion_sort(data_t array[], int size);
void selection_sort(data_t array[], int size);
void merge_sort(data_t array[], int size);
void merge(data_t array[], data_t left[], data_t right[], int Lsize, int Rsize);
void print_array(data_t array[], int size);
void quick_sort(data_t array[], int start, int end);
int partition(data_t array[], int start, int end);

#endif


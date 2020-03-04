#ifndef _SLIST_H_
#define _SLIST_H_
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE 1
#define LIST_EMPTY 2
#define DATA_NOT_FOUND 3
#define WRONG_INDEX 4

typedef int data_t;

typedef struct single_link_list
{
	data_t data;
	struct single_link_list *link;
}SList;

SList* sl_create_node(void);
int sl_isempty(SList *head);
int sl_insert_first(SList **head, SList **tail, data_t info);
int sl_insert_last(SList **head, SList **tail, data_t info);
int sl_delete_first(SList **head, SList **tail);
int sl_delete_last(SList **head, SList **tail);
int sl_delete_element(SList **head, SList **tail, data_t info);
int sl_insert_before(SList **head, SList **tail, data_t info, data_t binfo);
int sl_insert_after(SList **head, SList **tail, data_t info, data_t ainfo);
int sl_delete_list(SList **head, SList **tail);
int sl_count(SList **head, data_t info, int *count);
int sl_get_nth(SList **head, data_t *info, int index);
int sl_include_nth(SList **head, SList **tail, data_t info, int index);
int sl_sorted_insert(SList **head, SList **tail, data_t info);
int sl_insert_sort(SList **head, SList **tail);
int sl_append(SList **head, SList **head1, SList **tail, SList **tail1);
int sl_remove_duplicates(SList **head, SList **tail);
int sl_reverse(SList **head, SList **tail);
void sl_print_list(SList **head, int result);

#endif




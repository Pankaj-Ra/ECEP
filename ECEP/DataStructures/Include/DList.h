#ifndef _DLIST_H_
#define _DLIST_H_
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE 1
#define LIST_EMPTY 2
#define DATA_NOT_FOUND 3

typedef int data_t;

typedef struct double_link_list
{
	struct double_link_list *prev;
	data_t data;
	struct double_link_list *next;
}DList;

DList* dl_create_node(void);
int dl_isempty(DList *head);
int dl_insert_first(DList **head, data_t info);
int dl_insert_last(DList **head, data_t info);
int dl_delete_first(DList **head);
int dl_delete_last(DList **head);
int dl_delete_element(DList **head, data_t info);
int dl_insert_before(DList **head, data_t info, data_t binfo);
int dl_insert_after(DList **head, data_t info, data_t binfo);
int dl_delete_list(DList **head);
void dl_print_list(DList **head, int result);

#endif




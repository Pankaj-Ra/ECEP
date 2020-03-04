#include<stdio.h>
#include<stdlib.h>
#define FAILURE 0
#define SUCCESS 1
#define LIST_EMPTY 2
#define DATA_NOT_FOUND 3

typedef int data_t;

typedef struct double_link_list
{
	struct double_link_list *prev;
	data_t info;
	struct double_link_list *next;
}DList;

DList* sl_create(void)
{
	return malloc(sizeof(DList));
}

int sl_insert_before(DList **head, DList **tail, data_t info, data_t binfo)
{
	if ((*head) == NULL)
	{
		return LIST_EMPTY;
	}

        DList *new = sl_create();

	if (new == NULL)
	{
		return FAILURE;
	}
	
	new->data = info;
	new->prev = new->next = NULL;

	if ((*head)->data = binfo)
	{
		new->next = (*head);
		(*head)->prev = new;
		(*head) = new;
		return SUCCESS;
	}


	DList *temp = (*head);

	while (temp->data != binfo)
	{
		temp = temp->next;

		if ((temp->next == NULL) && (temp->data != binfo))
		{
			return DATA_NOT_FOUND;
		}
	}
        
	new->next = temp;
	new->prev = temp->prev;
	new->prev->next = new;
	temp->prev = new;

	return SUCCESS;
}

int main()
{






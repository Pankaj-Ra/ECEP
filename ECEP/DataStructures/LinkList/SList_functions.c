#include "../Include/SList.h"

SList* sl_create_node(void)
{
	return (malloc(sizeof(SList)));
}

int sl_isempty(SList *head)
{
	if (head == NULL)
	{
		return LIST_EMPTY;
	}
	return 0;
}

int sl_insert_first(SList **head, SList **tail, data_t info)
{

	SList *new = sl_create_node();

	if (new == NULL)
	{
		return FAILURE;
	}

	new->data = info;
	new->link = NULL;

	if (sl_isempty(*head))
	{
		(*head) = (*tail) = new;
		return SUCCESS;
	}

	new->link = (*head);
	(*head) = new;
	return SUCCESS;
}

int sl_insert_last(SList **head, SList **tail, data_t info)
{

	SList *new = sl_create_node();

	if (new == NULL)
	{
		return FAILURE;
	}

	new->data = info;
	new->link = NULL;

	if (sl_isempty(*head))
	{
		(*head) = (*tail) = new;
		return SUCCESS;
	}

	(*tail)->link = new;
	(*tail) = new;

	return SUCCESS;
}


int sl_delete_first(SList **head, SList **tail)
{

	if (sl_isempty(*head))
	{
		return LIST_EMPTY;
	}

	if ((*head) == (*tail))
	{
		free(*head);
		(*head) = (*tail) = NULL;
		return SUCCESS;
	}

	SList *temp = (*head);
	(*head) = (*head)->link;
	free(temp);

	return SUCCESS;
}

int sl_delete_last(SList **head, SList **tail)
{

	if (sl_isempty(*head))
	{
		return LIST_EMPTY;
	}

	if ((*head) == (*tail))
	{
		free(*head);
		(*head) = (*tail) = NULL;
		return SUCCESS;
	}

	SList *temp = (*head);

	while (temp->link != *tail)
	{
		temp = temp->link;
	}

	free(*tail);
	(*tail) = temp;
	temp->link = NULL;

	return SUCCESS;
}

int sl_delete_element(SList **head, SList **tail, data_t info)
{

	if (sl_isempty(*head))
	{
		return LIST_EMPTY;
	}

	if (((*head) == (*tail) && ((*head)->data != info)))
	{
		return DATA_NOT_FOUND;
	}

	SList *temp = (*head);

	if ((*head)->data == info)
	{
		if ((*head) != (*tail))
		{
			(*head) = (*head)->link;
			free(temp);

			return SUCCESS;
		}

		free(*head);
		(*head) = (*tail) = NULL;
		return SUCCESS;
	}

	while (temp->link->data != info)
	{
		temp = temp->link;
		if (temp->link == NULL)
		{
			return DATA_NOT_FOUND;
		}
	}

	SList *temp2 = temp->link;

	if (temp2 == (*tail))
	{
		(*tail) = temp;
		temp->link = NULL;
	}
	else
	{
	temp->link = temp2->link;
	}
	free(temp2);

	return SUCCESS;
}

int sl_insert_before(SList **head, SList **tail, data_t info, data_t binfo)
{

	SList *new = sl_create_node();

	if (new == NULL)
	{
		return FAILURE;
	}
	new->data = info;
	new->link = NULL;

	if (sl_isempty(*head))
	{
		return LIST_EMPTY;
	}

	if ((*head)->data == binfo)
	{
		new->link = (*head);
		(*head) = new;
		return SUCCESS;
	}

	SList *temp = (*head);

	while (temp->link->data != binfo)
	{
		temp = temp->link;
		if (temp->link == NULL)
		{
			return DATA_NOT_FOUND;
		}
	}

	new->link = temp->link;
	temp->link = new;

	return SUCCESS;
}

int sl_insert_after(SList **head, SList **tail, data_t info, data_t ainfo)
{

	SList *new = sl_create_node();

	if (new == NULL)
	{
		return FAILURE;
	}
	new->data = info;
	new->link = NULL;

	if (sl_isempty(*head))
	{
		return LIST_EMPTY;
	}

	SList *temp = (*head);

	while (temp->data != ainfo)
	{
		if (temp->link == NULL)
		{
			return DATA_NOT_FOUND;
		}
		temp = temp->link;
	}

	new->link = temp->link;
	temp->link = new;

	if ((*tail) == temp)
	{
		(*tail) = new;
	}

	return SUCCESS;
}

int sl_delete_list(SList **head, SList **tail)
{

	if (sl_isempty(*head))
	{
		return LIST_EMPTY;
	}

	if ((*head) == (*tail))
	{
		free(*head);
		(*head) = (*tail) = NULL;
		return SUCCESS;
	}

        SList *temp = (*head);
	while (temp != (*tail))
	{
		(*head) = (*head)->link;
		free(temp);
                temp = (*head);
	}
        free(temp);

	(*head) = (*tail) = NULL;
	
	return SUCCESS;
}

int sl_count(SList **head, data_t info, int *count)
{

	if (sl_isempty(*head))
	{
		return LIST_EMPTY;
	}

	SList *temp = (*head);

	if (temp->data == info)
	{
		*count += 1;
	}
	while (temp->link != NULL)
	{
		temp = temp->link;
		if (temp->data == info)
		{
			*count += 1;
		}
	}

	if (*count)
	{
		return SUCCESS;
	}

	return DATA_NOT_FOUND;
}

int sl_get_nth(SList **head, data_t *info, int index)
{

	if (sl_isempty(*head))
	{
		return LIST_EMPTY;
	}
        
	if (index >= 0)
	{
	SList *temp = (*head);

	for (index; index > 0; index--)
	{
		if (temp->link == NULL)
		{
			return WRONG_INDEX;
		}
		temp = temp->link;
	}

	*info = temp->data;

	return SUCCESS;
	}

	return WRONG_INDEX;
}

int sl_insert_nth(SList **head, SList **tail, data_t info, int index)
{

	SList *new = sl_create_node();

	if (new == NULL)
	{
		return FAILURE;
	}

	new->data = info;
	new->link = NULL;

	if (sl_isempty(*head))
	{
		return LIST_EMPTY;
	}

	if (index == 0)
	{
		new->link = (*head);
		(*head) = new;
		return SUCCESS;
	}

	if (index > 0)
	{

		SList *temp = (*head);

		for (index; index > 1; index--)
		{
			if (temp->link == NULL)
			{
				return WRONG_INDEX;
			}
			temp = temp->link;
		}

		if (temp->link == NULL)
		{
			(*tail) = new;
		}

		new->link = temp->link;
		temp->link = new;

		return SUCCESS;
	}

	return WRONG_INDEX;
}

int sl_sorted_insert(SList **head, SList **tail, data_t info)
{

	if (sl_isempty(*head))
	{
		return LIST_EMPTY;
	}

	SList *temp = (*head);

	if (temp->data >= info)
	{
		sl_insert_first(head, tail, info);
		return SUCCESS;
	}

	while (temp->link->data < info)
	{
		temp = temp->link;
		if (temp->link == NULL)
		{
			break;
		}
	}
	sl_insert_after(head, tail, info, temp->data);

	return SUCCESS;
}

/*int sl_insert_sort(SList **head, SList **tail)
{

	if (sl_isempty(*head))
	{
		return LIST_EMPTY;
	}

	SList *temp1 = (*head);
	SList *temp2 = (*head);

	while (temp1->link != NULL)
	{
		sl_sorted_insert(head, tail, temp2->data);
		temp1 = (*head);

		while (temp1->link != temp2)
		{
			temp1 = temp1->link;
		}
		temp1->link = temp2->link;
		free(temp2);
		temp2 = temp1->link;
	}

	return SUCCESS;
}*/

int sl_insert_sort(SList **head, SList **tail)
{

	if (sl_isempty(*head))
	{
		return LIST_EMPTY;
	}

	SList *temp;
	SList *temp1 = (*head);
	SList *temp2 = temp1->link;

	while (temp1->link != NULL)
	{
		while (temp2->link != NULL)
		{
			if ((*head)->data > (*head)->link->data)
			{
				temp = (*head)->link;
				(*head)->link = temp->link;
				temp->link = (*head);
				(*head) = temp;
				temp1 = (*head);
				temp2 = temp1->link;
			}
			if (temp1->link->data >= temp2->link->data)
			{
			temp = temp2->link;
			temp2->link = temp->link;
			if (temp == (*tail))
			{
				(*tail) = temp2;
			}
			temp->link = temp1->link;
			temp1->link = temp;
			continue;
			}
			temp2 = temp2->link;
		}
		temp1 = temp1->link;
		temp2 = temp1->link;
	}

	return SUCCESS;
}

int sl_append(SList **head, SList **head1, SList **tail, SList **tail1)
{

	if (sl_isempty(*head))
	{
		return LIST_EMPTY;
	}

	if (sl_isempty(*head1))
	{
		return LIST_EMPTY;
	}

	(*tail)->link = (*head1);
	(*tail) = (*tail1);

	return SUCCESS;
}

int sl_split_list(SList **head, SList **head1, SList **tail, SList **tail1)
{
	int count = 0;

	if (sl_isempty(*head))
	{
		return LIST_EMPTY;
	}

	SList *temp = (*head);
	count++;

	while (temp->link != NULL)
	{
		temp = temp->link;
		count++;
	}
	if (count & 1)
	{
		count = count/2 + 1;
	}
	else
	{
		count /= 2;
	}

	temp = (*head);

	while (temp->link != NULL)
	{
		count--;
		if (count == 0)
		{
			(*head1) = temp->link;
			(*tail) = temp;
			temp->link = NULL;
			temp = (*head1);
			continue;
		}
		temp = temp->link;
	}

	(*tail1) = temp;

	return SUCCESS;
}

int sl_remove_duplicates(SList **head, SList **tail)
{
   
	if (sl_isempty(*head))
	{
		return LIST_EMPTY;
	}

	SList *temp, *temp1, *temp2;

	for (temp = (*head); temp->link != NULL; temp = temp->link)
	{
		temp2 = temp;
		while (temp2->link != NULL)
		{
			if (temp2->link->data == temp->data)
			{
				temp1 = temp2->link;

				if (temp1 == (*tail))
				{
					temp2->link = NULL;
					(*tail) = temp2;
					free(temp1);
					return SUCCESS;
				}

				temp2->link = temp2->link->link;
				free(temp1);
				continue;
			}
			temp2 = temp2->link;
		}
	}

	return SUCCESS;
}

int sl_sorted_merge(SList **head, SList **head1, SList **tail, SList **tail1)
{

	if (sl_isempty(*head))
	{
		return LIST_EMPTY;
	}

	if (sl_isempty(*head1))
	{
		return LIST_EMPTY;
	}

	SList *temp = (*head);
	SList *temp1 = (*head1);

	if (temp->data >= temp1->data)
	{
		(*head1) = (*head1)->link;
		temp1->link = temp;
		(*head) = temp1;
		temp = (*head);
	}

        while ((temp->link != NULL))
	{
		if ((temp->link->data >= (*head1)->data) && ((*head)->link != NULL))
		{
			(*head1) = (*head1)->link;
			temp1->link = temp->link;
			temp->link = temp1;
		}
		temp = temp->link;
		temp1 = (*head1);
		
		if (((*head1)->link == NULL) && (temp->link->data >= (*head1)->data))
		{
			temp1->link = temp->link;
			temp->link = temp1;
			(*head1) = (*tail1) = NULL;
			break;
		}
	}

	if ((temp->link == NULL) && ((*head1)->link != NULL))
	{
		(*tail)->link = temp1;
		(*tail) = (*tail1);
		(*head1) = (*tail1) = NULL;
	}

	return SUCCESS;
}

int sl_reverse(SList **head, SList **tail)
{

	int count = 0, i, j;

	if (sl_isempty(*head))
	{
		return LIST_EMPTY;
	}

	SList *temp1 = (*head);

	while (temp1->link != NULL)
	{
		temp1 = temp1->link;
		count++;
	}
        
	temp1 = (*head);

	SList *temp2 = temp1->link;
	SList *temp3 = temp2->link;

        for (i = count; i > 0; i--)
	{
		temp1->link = temp2->link;
		temp2->link = temp1;
		(*head) = temp2;

		for (j = i - 1; j > 0; j--)
		{
			temp2->link = temp3;
			temp1->link = temp3->link;
			temp3->link = temp1;

			if (temp1->link == NULL)
			{
				(*tail) = temp1;
			}
			temp2 = temp3;
			temp3 = temp1->link;
		}
		temp1 = (*head);
		temp2 = temp1->link;
		temp3 = temp2->link;
	}

	return SUCCESS;
}

void sl_print_list(SList **head, int result)
{
	if (!result)
	{
		printf("SUCCESS\n");

		if ((*head) == NULL)
		{
			printf("NULL");
		}
		else
		{
			SList *temp = (*head);
			while ((temp)->link != NULL)
			{
				printf("%d->", temp->data);
				temp = temp->link;
			}
			printf("%d->", temp->data);
		}
		printf("\n");
	}
	else
	{
		switch (result)
		{
			case 1:
				{
					printf("Failed to create the node\n");
					break;
				}
			case 2:
				{
					printf("Link List is empty\n");
					break;
				}
			case 3:
				{
					printf("Given Data is not found\n");
					break;
				}
			case 4:
				{
					printf("Given Index is not found\n");
					break;
				}
		}
	}
}





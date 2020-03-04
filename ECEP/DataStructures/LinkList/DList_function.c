#include "../Include/DList.h"

DList* dl_create_node(void)
{
	return (malloc(sizeof(DList)));
}

int dl_isempty(DList *head)
{
	if (head == NULL)
	{
		return LIST_EMPTY;
	}
	return 0;
}

int dl_insert_first(DList **head, data_t info)
{

	DList *new = dl_create_node();

	if (new == NULL)
	{
		return FAILURE;
	}

        new->prev = NULL;
	new->data = info;
	new->next = NULL;

	if (dl_isempty(*head))
	{
		(*head)  = new;
		return SUCCESS;
	}
        
	(*head)->prev = new;
	new->next = (*head);
	(*head) = new;
	return SUCCESS;
}

int dl_insert_last(DList **head, data_t info)
{

	DList *new = dl_create_node();

	if (new == NULL)
	{
		return FAILURE;
	}
        
	new->prev = NULL;
	new->data = info;
	new->next = NULL;

	if (dl_isempty(*head))
	{
		(*head) = new;
		return SUCCESS;
	}
        
	DList *temp = (*head);

	while (temp->next != NULL)
	{
		temp = temp->next;
	}
        
	new->prev = temp;
	temp->next = new;

	return SUCCESS;
}


int dl_delete_first(DList **head)
{

	if (dl_isempty(*head))
	{
		return LIST_EMPTY;
	}

	if ((*head)->next == NULL)
	{
		free(*head);
		(*head) = NULL;
		return SUCCESS;
	}

	DList *temp = (*head);
	(*head) = (*head)->next;
	(*head)->prev = NULL;
	free(temp);

	return SUCCESS;
}

int dl_delete_last(DList **head)
{

	if (dl_isempty(*head))
	{
		return LIST_EMPTY;
	}

	if ((*head)->next == NULL)
	{
		free(*head);
		(*head) = NULL;
		return SUCCESS;
	}

	DList *temp = (*head);

	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->prev->next = NULL;
	free(temp);

	return SUCCESS;
}

int dl_delete_element(DList **head, data_t info)
{

	if (dl_isempty(*head))
	{
		return LIST_EMPTY;
	}

	if ((*head)->data == info)
	{
		if ((*head)->next == NULL)
		{
			free(*head);
			(*head) = NULL;
			return SUCCESS;
		}
		(*head) = (*head)->next;
		free((*head)->prev);
		return SUCCESS;
	}

	DList *temp = (*head);

	while (temp->data != info)
	{
		if (temp->next == NULL)
		{
			return DATA_NOT_FOUND;
		}
		temp = temp->next;
	}

	if (temp->next == NULL)
	{
		temp->prev->next = NULL;
		free(temp);
		return SUCCESS;
	}
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	free(temp);

	return SUCCESS;
}

int dl_insert_before(DList **head, data_t info, data_t binfo)
{

	DList *new = dl_create_node();

	if (new == NULL)
	{
		return FAILURE;
	}

	new->prev = NULL;
	new->data = info;
	new->next = NULL;

	if (dl_isempty(*head))
	{
		return LIST_EMPTY;
	}

	DList *temp = (*head);

	while (temp->data != binfo)
	{
		if (temp->next == NULL)
		{
			return DATA_NOT_FOUND;
		}
		temp = temp->next;
	}

	new->next = temp;
	if (temp == (*head))
	{
		temp->prev = new;
		(*head) = new;
	}
	else
	{
		new->prev = temp->prev;
		new->next = temp;
		temp->prev = new;
	}

	return SUCCESS;
}

int dl_insert_after(DList **head, data_t info, data_t binfo)
{

	DList *new = dl_create_node();

	if (new == NULL)
	{
		return FAILURE;
	}
	new->prev = NULL;
	new->data = info;
	new->next = NULL;

	if (dl_isempty(*head))
	{
		return LIST_EMPTY;
	}

	DList *temp = (*head);

	while (temp->data != binfo)
	{
		if (temp->next == NULL)
		{
			return DATA_NOT_FOUND;
		}
		temp = temp->next;
	}

	new->next = temp->next;
	new->prev = temp;
	temp->next = new;

	return SUCCESS;
}

int dl_delete_list(DList **head)
{

	if (dl_isempty(*head))
	{
		return LIST_EMPTY;
	}

	while ((*head)->next != NULL)
	{
		(*head) = (*head)->next;
		free((*head)->prev);
	}
        free(*head);

	(*head) = NULL;
	
	return SUCCESS;
}

void dl_print_list(DList **head, int result)
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
		DList *temp = (*head);
		while ((temp)->next != NULL)
		{
			printf("%d->", temp->data);
			temp = temp->next;
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
		}
	}
}





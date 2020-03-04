#include "../Include/tree.h"

Tree *bst_create(void)
{
	return (malloc(sizeof(Tree)));
}

Tree *bst_insert(Tree *root, data_t info)
{
	Tree *new = bst_create();

        if (new == NULL)
	{
		printf("[Failed to create the node]\n");
		return root;
	}

	new->l_child = NULL;
	new->data = info;
	new->r_child = NULL;

	if (root == NULL)
	{
		root = new;
		return root;
	}
        
	Tree *temp = root;
	Tree *temp1 = temp;
	int flag = 0;

	while (temp != NULL)
	{
		if (temp->data == info)
		{
			printf("[Given data already exists in tree]\n");
			return root;
		}
		if (temp->data < info)
		{
			temp1 = temp;
			temp = temp->r_child;
			flag = 0;
		}
		else
		{
			temp1 = temp;
			temp = temp->l_child;
			flag = 1;
		}
	}
        
	if (flag == 1)
	{
		temp1->l_child = new;
	}
	else
	{
		temp1->r_child = new;
	}

	return root;
}

int bst_delete_node(Tree *root, data_t info)
{
	if (root == NULL)
	{
		return DATA_NOT_FOUND;
	}

	Tree *temp = root;
	Tree *par = root;
	int flag = 0;

	while (temp != NULL)
	{
		if (temp->data == info)
		{
			break;
		}
	        if (temp->data > info)
		{
			par = temp;
			temp = temp->l_child;
			flag = 0;
		}
		else
		{
			par = temp;
			temp = temp->r_child;
			flag = 1;
		}
	}

	if (temp == NULL)
	{
		return DATA_NOT_FOUND;
	}

	Tree *succ = temp;

        Loop:
	if (temp->r_child != NULL)
	{
		succ = temp->r_child;
		while (succ->l_child != NULL)
		{
 			par = succ;
			succ = succ->l_child;
			flag = 0;
		}
		temp->data = succ->data;
	}
	if (succ->r_child != NULL)
	{
		temp = succ;
		goto Loop;
	}
	else
	{
		if (succ->l_child != NULL)
		{
			par->l_child = succ->l_child;
		}
		else
		{
			if (flag == 0)
			{
				par->l_child = NULL;
			}
			else
			{
				par->r_child = NULL;
			}
		}
		free(succ);
		return SUCCESS;
	}
}

int find_min(Tree *root)
{
	Tree *temp = root;

	if (root == NULL)
	{
		return DATA_NOT_FOUND;
	}

	while (temp->l_child != NULL)
	{
		temp = temp->l_child;
	}

	return temp->data;
}

int find_max(Tree *root)
{
	Tree *temp = root;

	if (root == NULL)
	{
		return DATA_NOT_FOUND;
	}

	while (temp->r_child != NULL)
	{
		temp = temp->r_child;
	}

	return temp->data;
}

data_t search_node(Tree *root, data_t info)
{
	if (root == NULL)
	{
		return DATA_NOT_FOUND;
	}

	Tree *temp = root;

	while (temp != NULL)
	{
		if (temp->data == info)
		{
			return temp->data;
		}
		if (temp->data < info)
		{
			temp = temp->r_child;
		}
		else
		{
			temp = temp->l_child;
		}
	}

	return DATA_NOT_FOUND;
}

void inorder(Tree *root)
{
	if (root == NULL)
	{
		return;
	}

	inorder(root->l_child);
	printf("  %d", root->data);
	inorder(root->r_child);
}

void preorder(Tree *root)
{
	if (root == NULL)
	{
		return;
	}

	preorder(root->l_child);
	preorder(root->r_child);
	printf("  %d", root->data);
}

void postorder(Tree *root)
{
	if (root == NULL)
	{
		return;
	}

	printf("  %d", root->data);
	postorder(root->l_child);
	postorder(root->r_child);
}


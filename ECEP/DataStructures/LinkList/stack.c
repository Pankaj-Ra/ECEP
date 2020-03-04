#include "../Include/stack.h"

int push_stack(stack *s, data_t data)
{
	if (s->top == SIZE - 1)
	{
		return STACK_FULL;
	}

	(s->top)++;

	s->array[s->top] = data;

	return SUCCESS;
}

int pop_stack(stack *s, data_t *data)
{
	if (s->top == -1)
	{
		return STACK_EMPTY;
	}

	*data = s->array[s->top];

	(s->top)--;

	return SUCCESS;
}

int push_stk(stack *e, int data)
{
	if (e->top == SIZE - 1)
	{
		return STACK_FULL;
	}

	(e->top)++;

	e->stk[e->top] = data;

	return SUCCESS;
}

int pop_stk(stack *e, int *data)
{
	if (e->top == -1)
	{
		return STACK_EMPTY;
	}

	*data = e->stk[e->top];

	(e->top)--;

	return SUCCESS;
}

int precidence(char operate)
{
	if (operate == '(')
	{
		return 0;
	}
	if (operate == ')')
	{
		return 0;
	}
	if ((operate == '+') || (operate == '-'))
	{
		return 1;
	}
	if ((operate == '*') || (operate == '/') || (operate == '%'))
	{
		return 2;
	}
	if (operate == '^')
	{
		return 3;
	}

	return 4;

}

void reverse_string(char *infix, int size)
{
	char *temp = infix, store;

	size -= 1;
	while (size > 0)
	{
		store = *temp;
		*temp = *(temp + size);
		*(temp + size) = store;
		temp++;
		size -= 2;
	}
}

char *infix_to_postfix(char *infix, int size)
{
	stack s;
	s.top = -1;
	int i, j = 0;
	data_t data;
	char *postfix = calloc(size, sizeof(char));

	for (i = 0; i < size; i++)
	{
		if (isalnum(infix[i]))
		{
			postfix[j++] = infix[i];
		}
		else
		{
			if (infix[i] == '(')
			{
				push_stack(&s, infix[i]);
			}
			else
			{
				if (infix[i] == ')')
				{
					pop_stack(&s, &data);
					postfix[j++] = data;
					while (data != '(')
					{
						pop_stack(&s, &data);
						if (data != '(')
						{
							postfix[j++] = data;
						}
					}
				}
				else
				{
					while ((precidence(infix[i]) <= precidence(s.array[s.top])) && (s.top != -1))
					{
						pop_stack(&s, &data);
						postfix[j++] = data;
					}
					push_stack(&s, infix[i]);
				}
			}
		}
	}
	while (s.top != -1)
	{
		pop_stack(&s, &data);
		postfix[j++] = data;
	}

	return postfix;
}

char *infix_to_prefix(char *infix, int size)
{

	stack s;
	s.top = -1;
	int i, j = 0;
	data_t data;
	char *prefix = calloc(size, sizeof(char));

	reverse_string(infix, size);
        
	for (i = 0; i < size ; i++)
	{
		if (isalnum(infix[i]))
		{
			prefix[j++] = infix[i];
		}
		else
		{
			if (infix[i] == ')')
			{
				push_stack(&s, infix[i]);
			}
			else
			{
				if (infix[i] == '(')
				{
					pop_stack(&s, &data);
					prefix[j++] = data;
					while (data != ')')
					{
						pop_stack(&s, &data);
						if (data != ')')
						{
							prefix[j++] = data;
						}
					}
				}
				else
				{
					while (((precidence(infix[i])) < precidence(s.array[s.top])) && (s.top != -1))
					{
						pop_stack(&s, &data);
						prefix[j++] = data;
					}
					push_stack(&s, infix[i]);
				}
			}
		}
	}
	while (s.top != -1)
	{
		pop_stack(&s, &data);
		prefix[j++] = data;
	}

	return prefix;
}

int evaluate_postfix(char *postfix, int size)
{
	stack e;
	e.top = -1;
	int data = 0, store;
	int i, j = 0;

	for (i = 0; i < size; i++)
	{
		if (isalnum(postfix[i]))
		{
			store = (postfix[i]) - 48;
			push_stk(&e, store);
		}
		else
		{
			pop_stk(&e, &data);
			store = data;
			pop_stk(&e, &data);
			switch (postfix[i])
			{
				case '+':
					store = data + store;
					break;
				case '-':
					store = data - store;
					break;
				case '*':
					store = data * store;
					break;
				case '/':
					store = data / store;
					break;
			}
			push_stk(&e, store);
		}
	}
	pop_stk(&e, &data);

	return data;
}

int evaluate_prefix(char *prefix, int size)
{
	stack e;
	e.top = -1;
	int data = NULL, store;
	int i, j = 0;
        
	for (i = 0; i < size; i++)
	{
		if (isalnum(prefix[i]))
		{
			store = prefix[i] - 48;
			push_stk(&e, store);
		}
		else
		{
			pop_stk(&e, &data);
			store = data;
			pop_stk(&e, &data);
			switch (prefix[i])
			{
				case '+':
					store = store + data;
					break;
				case '-':
					store = store - data;
					break;
				case '*':
					store = store * data;
					break;
				case '/':
					store = store / data;
					break;
			}

			push_stk(&e, store);
		}
	}
	pop_stk(&e, &data);

	return data;
}

int binary_search(int *array, int size, int key)
{
	int start = 0;
	int mid, end = size - 1;

	while (start <= end)
	{
		mid = (start + end)/2;
		if (array[mid] == key)
		{
			return mid;
		}
		if (array[mid] > key)
		{
			end = mid - 1;
		}
		if (array[mid] < key)
		{
			start = mid + 1;
		}
	}

	return DATA_NOT_FOUND;
}


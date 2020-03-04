#ifndef _STACK_H_
#define _STACK_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SUCCESS 0
#define STACK_FULL 1
#define STACK_EMPTY 2
#define DATA_NOT_FOUND -1
#define SIZE 25
#define MAX 30

typedef char data_t;

typedef struct stack_array
{
	data_t array[SIZE];
	int stk[SIZE];
	int top;
}stack;

int push_stack(stack *s, data_t data);
int pop_stack(stack *s, data_t *data);
int push_stk(stack *e, int  data);
int pop_stk(stack *e, int *data);
int precidence(char operate);
void reverse_string(char *infix, int size);
char *infix_to_postfix(char *infix, int size);
char *infix_to_prefix(char *infix, int size);
int evaluate_postfix(char *postfix, int size);
int evaluate_prefix(char *prefix, int size);

#endif


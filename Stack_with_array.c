/*STACK WITH ARRAY*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 1000

typedef struct stack stack;

struct stack
{
	int current_size;
	int items[MAX_STACK_SIZE];
};

stack *create_stack()
{
	stack *new_stack = (stack*) malloc (sizeof(stack));
	new_stack->current_size = 0;
	return new_stack;
}

int is_filled(stack *stack)
{
	return stack->current_size;
}

void push(stack *stack, int item)
{
	if(stack->current_size == MAX_STACK_SIZE)
		printf("Stack Overflow\n");
	else
		stack->items[stack->current_size++] = item;
}

int pop(stack *stack)
{
	if(!is_filled(stack))
	{
		printf("Stack Underflow\n");
		return -1;
	}
	else
		return stack->items[--stack->current_size];
}

int peek(stack *stack)
{
	if(!is_filled(stack))
	{
		printf("Stack Underflow\n");
		return -1;
	}
	else
		return stack->items[stack->current_size - 1];
}

void print(stack *stack)
{
	for(int i=0; i<stack->current_size; i++)
		printf("%d ", stack->items[i]);
}

void main()
{
	stack *stacking = create_stack();
	int n = 10;
	int item;
	while(n--)
	{
		scanf("%d", &item);
		push(stacking, item);
	}
	print(stacking);
	free(stacking);
}

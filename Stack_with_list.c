/*STACK WITH LIST*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node 
{
	int item;
	struct node *previous;
};

typedef struct stack stack;

struct stack
{
	node *top;
};

stack *create_stack()
{
	stack *new_stack = (stack*) malloc (sizeof(stack));
	new_stack->top = NULL;
	return new_stack;
}

int is_empty(stack *stack)
{
	return (stack->top == NULL);
}

void push(stack *stack, int item)
{
	node *new_top = (node*) malloc (sizeof(node));
	new_top->item = item;
	new_top->previous = stack->top;
	stack->top = new_top;
}

void pop(stack *stack)
{
	node *current = (node*) malloc (sizeof(node));
	if(is_empty(stack))
		printf("Stack Underflow\n");
	else 
	{
		current = stack->top->previous;
		stack->top->previous = NULL;
		stack->top = current;
	}	
}

int peek(stack *stack)
{
	if(is_empty(stack))
		printf("Stack Underflow\n");
	else 
		return stack->top->item;
}

void print(stack *stack)
{
	if(stack->top != NULL)
	{	
		printf("%d ", stack->top->item);
		pop(stack);
		print(stack);
	}
	else 
		return;	
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

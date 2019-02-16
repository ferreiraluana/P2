#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void pop(stack *stack, int *command)
{
	
	if(is_empty(stack))
		return 0;
	else 
	{
	    node *current = (node*) malloc (sizeof(node));
	    current = stack->top->previous;
		stack->top->previous = NULL;
		stack->top = current;
	    (*command)--;
	}	

}

int peek(stack *stack)
{
	if(is_empty(stack))
		return 0;
	else 
		return stack->top->item;
	
}

void main()
{
	stack *stack_back = create_stack();
	stack *stack_forward = create_stack();	
	char item[10];
	int b = -1;
	int f = 0;
	int enter = 0;
	while(scanf("%s",&item) != EOF)
	{
		if(!strcmp(item, "ENTER"))
		{	
			if(enter == 0)
			{
				enter=1; 
				b++;
			}
			else
			{	
				push(stack_back, ++b);
				pop(stack_forward, &f);
			}	
		}
		else if(!strcmp(item, "BACK"))
		{
		   pop(stack_back,&b);
           push(stack_forward, ++f);
		}
		else if(!strcmp(item, "FORWARD"))
		{
		   push(stack_back, ++b);
		   pop(stack_forward, &f);
		}	
	}
	printf("BACK: %d\n", peek(stack_back));
	printf("FORWARD: %d\n", peek(stack_forward));
	free(stack_back);
	free(stack_forward);
}

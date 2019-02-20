#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	char item;
	struct node *next;	
	struct node *previous;
};

typedef struct node node;

node *create_list() {return NULL;}

node *add_to_tail(node *tail, char item)
{
	node *new_node = (node*) malloc(sizeof(node));
	new_node -> item = item;
	new_node -> previous = tail;
	if(tail != NULL)
		tail -> next = new_node;
	new_node -> next = NULL;
	return new_node;
} 

void print_forward(node *head)
{
	if(head != NULL)
	{
		printf("%d ", head -> item);
		print_forward(head -> next);
	}	
}

node *free_list(node *head)
{
	node *aux = head;
	while(aux != NULL)
	{
		head = head -> next;
		free(aux);
		aux = head;
	}
	return aux;
}

void biggest_sequence(node *head)
{
	node *current;
	int initial_position = 0;
	int final_position = 0;
	while(head != NULL)
	{
		if(current->next->item == current->item)
			final_position++;
		else	
			{
				initial_position++;
				final_position = initial_position;
			}
		head = head->next;
	}
	printf("%d %d\n", initial_position, final_position);
}

void main()
{
	node *head = create_list();
	node *tail = NULL;
	int i;
	int item;
	char sequence[1000];
	while(1)
	{
		
		gets(sequence);
		if(strlen(sequence) == 1 && sequence[0] == '0') break;
		for(i=0; i<strlen(sequence); i++)
		{	
			item = *(sequence + i);
			if(head == NULL)
			{
				head = add_to_tail(head, item);
				tail = head;
			}
			else
				tail = add_to_tail(tail, item);
		}
		biggest_sequence(head);
	}
	head = free_list(head);
}

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int item;
	struct node *next;	
	struct node *previous;
};

typedef struct node node;

node *create_list() {return NULL;}

node *add_to_tail(node *tail, int item)
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

void main()
{
	node *head = create_list();
	node *tail = NULL;
	int item, i=0;
	int trash;
	char sequence[1000];
	gets(sequence);
	scanf("%c", &trash);
	while(sequence[i] != '\0')
	{
		head = sequence[i];
		if(head == NULL)
		{
			head = add_to_tail(head, item);
			tail = head;
		}
		else
			tail = add_to_tail(tail, item);
	}
	print_forward(head);
	head = free_list(head);
}
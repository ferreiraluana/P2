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

node *add_to_head(node *head, int item)
{
	node *new_node = (node*) malloc(sizeof(node));
	new_node -> item = item;
	new_node -> next = head;
	new_node -> previous = NULL;
	if(head != NULL)
		head -> previous = new_node;
	return new_node;
}

node *add_to_tail(node *tail, int item) //test
{
	node *new_node = (node*) malloc(sizeof(node));
	new_node -> item = item;
	new_node -> previous = tail;
	if(tail != NULL)
		tail -> next = new_node;
	new_node -> next = NULL;	
	return new_node;
}

void print_backward(node *tail)
{
	if(tail == NULL) return;
	printf("%d\n", tail -> item);
	print_backward(tail -> previous);
}
void print_forward(node *head)
{
	if(head != NULL)
	{
		printf("%d\n", head -> item);
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

node *search(node *head, int item)
{
	if(head == NULL || head -> item == item) return head;
	search(head -> next, item);	
}

node *remove_item(node *head, int item) 
{
	node *previous = NULL;
	node *current = head;
	while(current -> item != item && current != NULL)	
	{
		previous = current;
		current = current -> next;
	}
	if(current == NULL) return head;
	if(head == current)
		head = current -> next;
	else
		current -> previous -> next = current -> next;

	if(current -> next != NULL)
		current -> next -> previous = current -> previous;
	free(current);
	return head;
}

void main()
{
	node *head = create_list();
	node *tail = NULL;
	int item;
	while(1)
	{
		scanf("%d", &item);
		if(item == -1) break;
		if(head == NULL)
		{
			head = add_to_tail(head, item);
			tail = head;
		}
		else
			tail = add_to_tail(tail, item);
	}	
	head = remove_item(head, 2);
	//print_backward(tail);
	print_forward(head);
	head = free_list(head);
	//if (head == NULL) //check if memory is free
		//printf("EMPTY\n");
}

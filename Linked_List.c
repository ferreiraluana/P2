#include <stdio.h>
#include <stdlib.h>

struct node
{
	int item;
	struct node *next;
};

typedef struct node node;

node *create_list() {return NULL;}

node *add(node *head, int item)
{
	node *new_node = (node*) malloc(sizeof(node));
	new_node -> item = item; // *(new_node).item
	new_node -> next = head;
	return new_node;
}

void print_list(node *head)
{
	node *current = head;
	while(current != NULL)
	{
		printf("%d ", current -> item);
		current = current -> next;
	}
	printf("\n");
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
	else if(previous == NULL)
		head = current -> next;
	else
		previous -> next = current -> next;
	free(current);
	return head;
}

void main()
{
	node *head = create_list();
	int item;
	while(1)
	{
		scanf("%d", &item);
		if(item == -1) break;
		head = add(head, item);
	}
	print_list(head);
	head = remove_item(head, 21);
	print_list(head);
	head = free_list(head);
	//if (head == NULL) //check if memory is free
		//printf("EMPTY\n");
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node node;

struct node
{
	int item;
	int priority;
	node *next;
};

typedef struct priority_queue priority_queue;

struct priority_queue
{
	node *head;
};

priority_queue *create_priority_queue()
{
	priority_queue *new_priority_queue = (priority_queue*) malloc (sizeof(priority_queue));
	new_priority_queue->head = NULL;
	return new_priority_queue;
}

int is_empty(priority_queue *pq)
{
	return (pq->head == NULL);
}

void enqueue(priority_queue *pq, int i, int p)
{
	node *new_node = (node*) malloc (sizeof(node));
	new_node->item = i;
	new_node->priority = p;
	if((is_empty(pq)) || (p > pq->head->priority))
	{
		new_node->next = pq->head;
		pq->head = new_node;
	}
	else
	{
		node *current = pq->head;
		while((current->next != NULL) && (current->next->priority > p))
			current = current->next;
		new_node->next = current->next;
		current->next = new_node;
	}	
}

node *dequeue(priority_queue *pq)
{
	if(is_empty(pq))
	{
		printf("Priority Queue underflow\n");
		return NULL;
	}
	else
	{
		node *node = pq->head;
		pq->head = pq->head->next;
		node->next = NULL;
		return node;
	}
}

int maximum(priority_queue *pq)
{
	if(is_empty(pq))
	{
		printf("Priority Queue underflow\n");
		return -1;
	}
	else 
		return pq->head->item;
}

void print_priority_queue(priority_queue *pq)
{
	while(pq->head != NULL)
	{
	printf("%d\n", pq->head->item);
	pq->head = pq->head->next;
	}
}

void main()
{
	priority_queue *queue = create_priority_queue();
	int item; 
	int priority;
	while(1)
	{
		scanf("%d", &item);
		if(item == -1)
			break;
		scanf("%d", &priority);
		enqueue(queue, item, priority);
	}
	print_priority_queue(queue);
	free(queue);
}

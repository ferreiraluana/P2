// falta a funçao REMOVE
#include <stdio.h>
#include <stdlib.h>

typedef struct binary_tree btree;

struct binary_tree
{
	int item;
	int nodes;
	btree *left;
	btree *right;
};

/*Binary Tree ADT*/

btree *create_empty_btree();
btree *create_btree(int item, btree *left, btree *right);
btree *search(btree *bt, int item);
int is_empty(btree *bt);
void print_pre_order(btree *bt);
void print_in_order(btree *bt);
void print_post_order(btree *bt);

btree *create_empty_btree()
{
	return NULL;
}

btree *create_btree(int item, btree *left, btree *right)
{
	btree *new_btree = (btree*) malloc (sizeof(btree));
	new_btree->item = item;
	new_btree->nodes = 0;
	new_btree->left = left;
	new_btree->right = right;
	return new_btree;
}

int is_empty(btree *bt)
{
	return (bt == NULL);
}

btree *search(btree *bt, int item)
{
	if((bt == NULL) || (bt->item == item)) 
		return bt;
	else if(bt->item > item) 
		return search(bt->left, item);
	else 
		return search(bt->right, item);
}

int find(btree *bt, int item)
{
	if(bt == NULL) 
		return 0;
	else if(bt->item == item)
		return 1;
	else if(bt->item > item) 
		find(bt->left, item);
	else 
		find(bt->right, item);
}

btree *add(btree *bt, int item)
{
	if(bt == NULL) 
		bt = create_btree(item, NULL, NULL);
	else if(bt->item > item) 
		bt->left = add(bt->left, item);
	else 
		bt->right = add(bt->right, item);
	return bt;
}

/*ADD USING DOUBLE POINTER*/
void add_dp(btree **bt, int item)
{
	if(*bt == NULL) 
		*bt = create_btree(item, NULL, NULL);
	else if((*bt)->item > item) 
		add_dp(&(*bt)->left, item);
	else 
		add_dp(&(*bt)->right, item);
}

void print_pre_order(btree *bt)
{
	if(!is_empty(bt))
	{
		printf("%d ", bt->item);
		print_pre_order(bt->left);
		print_pre_order(bt->right);
	}
}

void print_in_order(btree *bt)
{
	if(!is_empty(bt))
	{
		print_in_order(bt->left);
		printf("%d ", bt->item);
		print_in_order(bt->right);
	}
}

void print_post_order(btree *bt)
{
	if(!is_empty(bt))
	{
		print_post_order(bt->left);
		print_post_order(bt->right);
		printf("%d ", bt->item);
	}
}

int Frequence(btree *bt, int item, int *frequence)
{
	int f;
	if(!is_empty(bt))
	{
		Frequence(bt->left, item, frequence);
		if(item == bt->item)
			*frequence += 1;
		//printf("item: %d f = %d\n", bt->item, *frequence);
		Frequence(bt->right, item, frequence);
	}
	return *frequence;

}

void main()
{
	btree *bt = create_empty_btree();
	int n;
	int item;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d", &item);
		if(!find(bt, item))
		{	
			bt = add(bt, item);
			bt->nodes++;
		}	
	}
	printf("%d\n", bt->nodes);
	/*to calculate a frequence of an item in the tree*/
	// scanf("%d", &item);
	// int frequence = 0;
	// printf("%d\n", Frequence(bt, item, &frequence));
}

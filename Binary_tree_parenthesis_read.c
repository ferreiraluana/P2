#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int the_index = 0;

typedef struct binary_tree binary_tree;
struct binary_tree
{
    int item;
    binary_tree *left;
    binary_tree *right;
};

binary_tree* create_empty()
{
  return NULL;
}

int empty(binary_tree *bt)
{
  return (bt == NULL);
}

binary_tree* create_binary_tree(int it,binary_tree *left,binary_tree *right)
{
  binary_tree* new_binary_tree = (binary_tree*)malloc(sizeof(binary_tree));
  new_binary_tree->item = it;
  new_binary_tree->left = left;
  new_binary_tree->right = right;
  return new_binary_tree;
}

binary_tree* read_binary_tree(char *text) 
{
  binary_tree *bt = create_empty();
  int integer, i=0;
  char extractText[100];

  while(text[the_index] == '(')
    the_index+=1;
  if(text[the_index] == ')')
  {
    the_index++;
    return NULL;
  }
  elsethe_index
  {
    while(text[the_index] != '(')
    {
      extractText[i++] = text[the_index];
      the_index+=1;
    }
    extractText[i] = '\0';
    integer = atoi(extractText);
    bt = create_binary_tree(integer,NULL,NULL);
    bt->left = read_binary_tree(text);
    bt->right = read_binary_tree(text);
  }
  the_index+=1;
  return bt;
}

void print_pre_order(binary_tree* bt) 
{
  if(!empty(bt))
  {
    printf("%d ", bt->item);
    print_pre_order(bt->left);
    print_pre_order(bt->right);
  }
}
void print_in_order(binary_tree *bt) 
{
  if(!empty(bt))
  {
    print_in_order(bt->left);
    printf("%d ", bt->item);
    print_in_order(bt->right);
  }
}
void print_post_order(binary_tree *bt)
{
  if(!empty(bt))
  {
    print_post_order(bt->left);
    print_post_order(bt->right);
    printf("%d ", bt->item);
  }
}

int search_(binary_tree *bt,int it)
{
  if(bt->item == it) return 1;
  if(bt == NULL) return -1;
  search_(bt->left,it);
  search_(bt->right,it);
}

void main()
{
  binary_tree *tree = create_empty();
  int n,i;
  char num[500];
  scanf("%[^\n]s", num);
  puts(num);
  getchar();

  tree = read_binary_tree(num);

  print_pre_order(tree);
  free(tree);

}

#include <stdio.h>
#include <stdlib.h>
void print(int *a, int size)
{
	int i;
	for(i=0; i<size; i++)
		printf("%d ", *(a+i));
}
void swap(int *array1, int *array2)
{
  int aux;
  aux = *array1;
  *array1 = *array2;
  *array2 = aux;
}
void quick_sort(int *array, int size)
{
  if(size <= 1) return;
  else
  {
    int pivot = array[size/2];
    int a = 0;
    int b = size-1;

    while(a<b)
    {
      while(array[a]<pivot && a<size)
      	a++;
      while(array[b]>pivot && b>=0)
      	b--;

      if(a==b)
      {
        swap(&array[a], &array[b]);
        a++;
      }
    }

    quick_sort(array,b);
    quick_sort(array + a, size-a);
  }
}
int main()
{
	int *a = (int*) malloc(sizeof(int));
	int i=0;
	while(scanf("%d", (a+i)))
	{
		if(*(a+i)==-1)
			break;
		a = (int*) realloc(a, (i+1)*sizeof(int));
		i++;		
	}

	quick_sort(a, i);
	print(a, i);
}

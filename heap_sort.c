#include<stdio.h>

#define parent(i) (i+1)/2-1
#define left(i) (i)*2+1
#define right(i) (i+1)*2

typedef int elem;
typedef struct heap{
	elem *a;
	int length;
	int heap_size;
}heap;

void swap(elem *a, elem *b)
{
	elem tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void max_heapfy(heap *A, int i)
{
	int l = left(i);
	int r = right(i);
	int largest;
	if(l < A->heap_size && A->a[l] > A->a[i])
		largest = l;
	else largest = i;
	if(r < A->heap_size && A->a[r] > A->a[largest])
		largest = r;
	if(largest != i){
		swap(&A->a[i], &A->a[largest]);
		max_heapfy(A, largest);
	}
}

void build_max_heap(heap *A)
{
	int i;
	A->heap_size = A->length;
	for(i=A->length/2-1; i>=0;i--)
		max_heapfy(A,i);	
}

void heap_sort(heap *A)
{
	build_max_heap(A);
	int i;
	for(i = A->length-1; i>=1; i--){
		swap(&A->a[0], &A->a[i]);
		A->heap_size -= 1;
		max_heapfy(A, 0);
	}
}

int main(void)
{
	heap h;
	h.length = 10;
	elem a[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
	h.a = a;

	heap_sort(&h);
	int i;
	for(i=0;i<h.length;i++)
		printf("%d ", h.a[i]);
	printf("\n");
	return 0;
}

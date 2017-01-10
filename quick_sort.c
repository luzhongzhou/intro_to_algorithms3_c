#include<stdio.h>

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int partition(int (* ptr_a)[12], int p, int r) //注意数组指针的写法
{
	int i = p-1;
	int j;
	for(j=p;j<r;j++){
		if((*ptr_a)[j] <= (*ptr_a)[r]){
			i += 1;
			swap(*ptr_a+i, *ptr_a+j);
		}
	}
	swap((*ptr_a)+i+1, (*ptr_a)+r);
	return i+1;
}

void quick_sort(int (*ptr_a)[12], int p, int r)
{
	int q;
	if(p<r){
		q = partition(ptr_a, p, r);
		quick_sort(ptr_a, p, q-1);
		quick_sort(ptr_a, q+1, r);	
	}
}

int main(void)
{
	int a[]={13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11};
	quick_sort(&a,0,11);
	int i;
	for(i=0;i<12;i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}

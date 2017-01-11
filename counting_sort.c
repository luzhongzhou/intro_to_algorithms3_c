#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ASIZE 8
void counting_sort(int a[], int b[], int n, int m)
{
	int *c = (int *)malloc((m+1)*sizeof(int));
	memset(c,0,m+1);
	int i;
	for(i=0;i<n;i++){
		c[a[i]]++;
	}
	for(i=1;i<=m;i++){
		c[i] += c[i-1];
	}
	for(i=0;i<n;i++){
		b[c[a[i]]-1]=a[i];
		c[a[i]]--;
	}
	free(c);
}

int main(void)
{
	int a[]={2, 5, 3, 0, 2, 3, 0, 3};
	int b[ASIZE];
	
	int m=a[0];
	int i;
	for(i=1;i<ASIZE;i++){
		if(a[i]>m)
			m=a[i];
	}
	
	counting_sort(a,b,ASIZE,m);
	
	for(i=0;i<ASIZE;i++)
		printf("%d ",b[i]);
	printf("\n");
	return 0;
}

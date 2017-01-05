#include<stdio.h>
#include<stdlib.h>

struct sub_array{
	int low;
	int high;
	long sum;
};

struct sub_array *find_max_crossing_subarray(int *a, int low, int mid, int high)
{
	int i;
	int i_left = mid, i_right = mid;
	long sum_left = a[mid], sum_right = a[mid];
	long tmp = a[mid];

	for(i = mid-1; i >= low; i--){
		tmp += a[i];
		if( tmp > sum_left){
			sum_left = tmp;
			i_left = i;			
		}
	}
	tmp = a[mid];
	for(i = mid+1; i <= high; i++){
		tmp += a[i];
		if(sum_right < tmp){
			sum_right = tmp;
			i_right = i;
		}
	}

	struct sub_array *ptr = (struct sub_array *)malloc(sizeof(struct sub_array));
	ptr->low = i_left;
	ptr->high = i_right;
	ptr->sum = sum_left + sum_right - a[mid];		
	
	return ptr;
}

struct sub_array *find_max_subarray(int *a, int low, int high)
{
	struct sub_array *ptr = (struct sub_array *)malloc(sizeof(struct sub_array));
	if(low == high){
		ptr->low = low;
		ptr->high = high;
		ptr->sum = a[low];
		return ptr;
	} 
	
	int mid = (low + high)/2;
	struct sub_array *ptr_left = find_max_subarray(a, low, mid);
	struct sub_array *ptr_right = find_max_subarray(a, mid+1, high);
	struct sub_array *ptr_mid = find_max_crossing_subarray(a, low, mid, high);

	if(ptr_left->sum >= ptr_right->sum && ptr_left->sum >= ptr_mid->sum){
		ptr = ptr_left;
		free(ptr_right);
		free(ptr_mid);
	}
	else if(ptr_right->sum >= ptr_left->sum && ptr_right->sum >= ptr_mid->sum){
		ptr = ptr_right;
		free(ptr_left);
		free(ptr_mid);
	}
	else {
		ptr = ptr_mid;
		free(ptr_left);
		free(ptr_right);
	}
	
	return ptr;
}

int main(void)
{
	int a[16]={13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
	struct sub_array *ptr = find_max_subarray(a, 0, 15);
	printf("low = %d, high = %d, sum = %ld\n", ptr->low, ptr->high, ptr->sum);
	free(ptr);
	return 0;
}

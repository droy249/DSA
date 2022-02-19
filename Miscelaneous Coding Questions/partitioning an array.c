/* Write a program to partition an array about a given pivot such that 
1) Elements ot the left of pivot are smaller than or equal to the pivot
2) Elements to the right of pivot are greater than the pivot

Video Link: https://youtu.be/if40LxQ8_Xo
 */
#include <stdio.h>

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void partition(int arr[], const int n, const int pivot){
	/* 0 to j-1 => <= pivot
	j to i-i => > pivot
	i to n => unkwown */
	int i = 0, j = 0;
	while(i < n) arr[i] <= pivot ? swap(&arr[i++], &arr[j++]) : ++i;
}

void printArray(const int *nums, const int *n){
	for(int i = 0; i < *n; ++i)
		printf("%d%s", nums[i], i != *n - 1  ? ", " : "\n");
}

int main(){
	int nums[] = {7,9,4,8,3,6,2,1};
	const int n = sizeof(nums)/sizeof(*nums), pivot = 5;
	printf("Array before partitioning: ");
	printArray(nums,&n);
	partition(nums,n,pivot);
	printf("\nArray after partitioning: ");
	printArray(nums,&n);
	printf("\n");	
}
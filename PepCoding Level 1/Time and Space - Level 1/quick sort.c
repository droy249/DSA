/* Write a program to peform Quick Sort on given array in-place.
Time Complexity: O(n log n) {O(n^2) in worst case}
Space Complexity: O(1)

There are many ways to choose a pivot:
1) Always pick first element as pivot.
2) Always pick last element as pivot (implemented below)
3) Pick a random element as pivot.
4) Pick median as pivot.

Time Complexity: O(n log n)
Space Complexity: O(1)

Detailed analysis: https://www.geeksforgeeks.org/time-complexities-of-all-sorting-algorithms/?ref=lbp#:~:text=%CE%A9(n%5E2,O(n%5E2)

Link: https://www.geeksforgeeks.org/quick-sort/

Video Link: https://youtu.be/kdO5Q0nmPjU?list=PL-Jc9J83PIiFc7hJ5eeCb579PS8p-en4f
 */
#include <stdio.h>

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int nums[], const int lo, const int hi, const int pivot){
	/* 0 to j-1 >===> < pivot
	j - 1 >====> = pivot
	j to i-1 >===> > pivot
	i to n >===> unkwown */
	int i = lo, j = lo;
	while(i <= hi) nums[i] <= pivot ? swap(&nums[i++], &nums[j++]) : ++i;
	return j - 1;
}

void quickSort(int nums[], int lo, int hi){
	if(lo >= hi) return;
	const int pivot = nums[hi];
	const int pivotIndex = partition(nums, lo, hi, pivot);
	quickSort(nums, lo, pivotIndex - 1);
	quickSort(nums, pivotIndex + 1, hi);
}

void printArray(const int *nums, const int *n){
	for(int i = 0; i < *n; ++i)
		printf("%d%s", nums[i], i != *n - 1  ? ", " : "\n");
}

int main(void) {
	int nums[] = {6,5,3,1,8,7,2,4};
	const n = sizeof(nums)/sizeof(*nums);
	printf("Array before sorting: ");
	printArray(nums,&n);
	quickSort(nums,0,n-1);
	printf("\nArray after sorting: ");
	printArray(nums,&n);
	printf("\n");
}
/* Write a program to peform Bubble Sort on given array in-place.
Time Complexity: O(n^2)
Space Complexity: O(1)

Reference Link: https://www.geeksforgeeks.org/bubble-sort/#:~:text=In%20Place%3A%20Yes-,Stable%3A%20Yes,-Due%20to%20its

Detailed complexity analysis: https://www.geeksforgeeks.org/time-complexities-of-all-sorting-algorithms/#:~:text=%C2%A0-,Bubble%20Sort,-%CE%A9(n)

Video Link: https://www.youtube.com/watch?v=Jv-eGC2xmtU&list=PL-Jc9J83PIiFc7hJ5eeCb579PS8p-en4f&index=1
 */
#include <stdio.h>

void swap(int *arr, int i, int j){
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void bubbleSort(int *arr, const int *n){
	for(int i = 1; i < *n; ++i)
		for(int j = 0; j < *n - i; ++j){
			if(arr[j+1] < arr[j])
				swap(arr, j+1, j);
			// printf("\nFor i = %d, j = %d: ", i, j);
			// printArray(arr,*n);
		}
}

void printArray(const int *nums, const int *n){
	for(int i = 0; i < *n; ++i)
		printf("%d%s", nums[i], i != *n - 1  ? ", " : "\n");
}

int main(void) {
	int nums[] = {6,5,3,1,8,7,2,4};
	const int n = sizeof(nums)/sizeof(*nums);
	printf("Array before sorting: ");
	printArray(nums,&n);
	bubbleSort(nums,&n);
	printf("\nArray after sorting: ");
	printArray(nums,&n);
	printf("\n");
}
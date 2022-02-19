/* Write a program to peform Insertion Sort on given array in-place.
Time Complexity: O(n^2)
Space Complexity: O(1)

Reference Link: https://www.geeksforgeeks.org/insertion-sort/#:~:text=Incremental%20Approach

Detailed complexity analysis: https://www.geeksforgeeks.org/time-complexities-of-all-sorting-algorithms/#:~:text=%C2%A0-,Insertion%20Sort,-%CE%A9(n)

Video Link: https://www.youtube.com/watch?v=MMt2x6an_i8&list=PL-Jc9J83PIiFc7hJ5eeCb579PS8p-en4f&index=3
 */
#include <stdio.h>

void insertionSort(int *arr, const int *n){
	for(int i = 1; i < *n; ++i){
		int key = arr[i], j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
			printf("\nFor i = %d, j = %d: ", i, j);
			printArray(arr,n);
        }
        arr[j + 1] = key;
	}
}

void printArray(const int *nums, const int *n){
	for(int i = 0; i < *n; ++i)
		printf("%d%s", nums[i], i != *n - 1  ? ", " : "\n");
}

int main(void) {
	const int nums[] = {6,5,3,1,8,7,2,4};
	const int n = sizeof(nums)/sizeof(*nums);
	printf("Array before sorting: ");
	printArray(nums,&n);
	insertionSort(nums,&n);
	printf("\nArray after sorting: ");
	printArray(nums,&n);
	printf("\n");
}
/* Write a program to peform Selection Sort on given array in-place.
Time Complexity: O(n^2)
Space Complexity: O(1)

Reference Link: https://www.geeksforgeeks.org/selection-sort/#:~:text=default%20implementation%20is-,not%20stable,-.%20However%20it%20can

Detailed complexity analysis: https://www.geeksforgeeks.org/time-complexities-of-all-sorting-algorithms/?ref=lbp#:~:text=%CE%A9(n%5E2,O(n%5E2)

Video Link: https://www.youtube.com/watch?v=EU9FIt1t-Is&list=PL-Jc9J83PIiFc7hJ5eeCb579PS8p-en4f&index=2
 */
#include <stdio.h>

void swap(int *a, int *b){
	int tmp = *a ;
	*a = *b;
	*b = tmp;
}

void selectionSort(int *nums, const int *n){
	for(int i = 0; i < *n - 1; ++i){
		int minIndex = i;
		for(int j = i + 1; j < *n; ++j)
			if(nums[j] < nums[minIndex])
				minIndex = j;
		swap(&nums[minIndex], &nums[i]);
		// printf("\nFor i = %d, minIndex = %d: ", i, minIndex);
		// printArray(nums,n);
	}
}

// Stable Selection Sort: Here the position of equal elements does not change unlike in normal version
// Link: https://www.geeksforgeeks.org/stable-selection-sort/#:~:text=A%20sorting%20algorithm%20is%20said%20to%20be%20stable%20if%20two%20objects%20with%20equal%20or%20same%20keys%20appear%20in%20the%20same%20order%20in%20sorted%20output%20as%20they%20appear%20in%20the%20input%20array%20to%20be%20sorted.
void stableSelectionSort(int a[], const int n) {
    // Iterate through array elements
    for (int i = 0; i < n - 1; ++i) {
 
        // Loop invariant : Elements till a[i - 1]
        // are already sorted.
 
        // Find minimum element from
        // arr[i] to arr[n - 1].
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (a[min] > a[j])
                min = j;
 
        // Move minimum element at current i.
        int key = a[min];
        while (min > i){
            a[min] = a[min - 1];
            min--;
        }
        a[i] = key;
    }
}

void printArray(int *nums, const int *n){
	for(int i = 0; i < *n; ++i)
		printf("%d%s", nums[i], i != *n - 1  ? ", " : "\n");
}

int main(void) {
	int nums[] = {6,5,3,1,8,7,2,4};
	const int n = sizeof(nums)/sizeof(*nums);
	printf("Array before sorting: ");
	printArray(nums,&n);
	selectionSort(nums,&n);
	printf("\nArray after sorting: ");
	printArray(nums,&n);
	printf("\n");
}
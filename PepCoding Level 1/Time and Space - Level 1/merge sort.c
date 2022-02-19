/* Write a program to peform Merge Sort on given array in-place.
Time Complexity: O(n log n)
Space Complexity: O(n)

Reference Link: https://www.geeksforgeeks.org/merge-sort/#:~:text=a%20typical%20implementation-,Stable%3A%20Yes,-Applications%20of%20Merge

Detailed complexity analysis: https://www.geeksforgeeks.org/time-complexities-of-all-sorting-algorithms/#:~:text=%C2%A0-,Merge%20Sort,-%CE%A9(n%20log

Video Link: https://www.youtube.com/watch?v=aiUHB-3EOg8&list=PL-Jc9J83PIiFc7hJ5eeCb579PS8p-en4f&index=5
 */

#include <stdio.h>

void merge(int *arr, const int l, const int m, const int r){
	const int n1 = m - l + 1, n2 = r - m;
	int leftHalf[n1], rightHalf[n2];
	for(int i = 0; i < n1; ++i) leftHalf[i] = arr[l + i];
	for(int i = 0; i < n2; ++i) rightHalf[i] = arr[m + 1 + i];
	
	int i = 0, j = 0, k = l;
	while(i < n1 && j < n2) arr[k++] = leftHalf[i] < rightHalf[j] ? leftHalf[i++] : rightHalf[j++];
	while(i < n1) arr[k++] = leftHalf[i++];
	while(j < n2) arr[k++] = rightHalf[j++];
}

void mergeSort(int *arr, int l, int r){
	if(l >= r) return;
	const int m = l + (r - l) / 2;
	mergeSort(arr, l, m);
	mergeSort(arr, m + 1, r);
	merge(arr, l, m, r);
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
	mergeSort(nums,0,n-1);
	printf("\nArray after sorting: ");
	printArray(nums,&n);
	printf("\n");
}
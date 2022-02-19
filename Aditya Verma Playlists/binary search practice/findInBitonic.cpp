/* Given a bitonic sequence of n distinct elements, write a program to 
 * find a given element x in the bitonic sequence in O(log n) time. A 
 * Bitonic Sequence is a sequence of numbers which is first strictly 
 * increasing then after a point strictly decreasing.
*/

#include <stdio.h>

int maxInBitonic(const int *nums, const int n) {
	// if(n < 3) return -1;
	int low = 0, high = n;
	while(low < high) {
		int mid = low + (high - low) / 2;
		*(nums + mid) > *(nums + mid + 1) ? high = mid : low = mid + 1;
	}
	// fprintf(stderr, "%d %d\n", low, high);
	return low == n or low == 0 ? -1 : low;
}

int increasingBinarySearch(const int *arr, int low, int high, const int &key) {
	if(low > high) return -1;
	const int mid = low + (high - low) / 2;
	if(arr[mid] == key) return mid;
	return key < arr[mid] ? increasingBinarySearch(arr,low,mid-1,key) : increasingBinarySearch(arr,mid+1,high,key);
}

int decreasingBinarySearch(const int *arr, int low, int high, const int &key) {
	if(low > high) return -1;
	const int mid = low + (high - low) / 2;
	if(arr[mid] == key) return mid;
	return key < arr[mid] ? decreasingBinarySearch(arr,mid+1,high,key) : decreasingBinarySearch(arr,low,mid-1,key);
}

int main() {
	const int nums[] = 
	// {3, 9, 18, 20, 17, 5, 1}
	// {5, 6, 7, 8, 9, 10, 3, 2, 1}
	{1, 4, 8, 3, 2}
	;const int n = sizeof(nums)/sizeof(*nums);
	
	int max = maxInBitonic(nums,n);
	
	while(true){
		printf("Enter element to search: ");
		int key; scanf("%d", &key);
		fflush(stdout);
		if(key < 0) break;
		
		const int index1 = increasingBinarySearch(nums,0,max-1,key), index2 = decreasingBinarySearch(nums,max,n-1,key);
		if(index1 == -1 and index2 == -1) printf("Element not found\n\n");
		else if(index1 == -1) printf("Element found at index %d\n\n", index2);
		else if(index2 == -1) printf("Element found at index %d\n\n", index1);
	}
	printf("Exiting...\n");
}

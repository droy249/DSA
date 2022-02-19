/* Given an array of integers which is initially increasing and
 * then decreasing, find the maximum value in the array in O(log n) time. A 
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
	return low == n || low == 0 ? -1 : low;
}

int main() {
	const int nums[] = 
	// {1,2,3,4,5}
	// {5,3,2,1}
	// {1,1,1,1,1,1}				// Will not work for arrays with repeating elements
	// {1, 4, 8, 3, 2}
	{-3, 9, 18, 20, 17, 5, 1}
	// {5, 6, 7, 8, 9, 10, 3, 2, 1}
	;const int n = sizeof(nums)/sizeof(*nums);
	
	const int index = maxInBitonic(nums,n);
	if(index == -1) printf("Array is not bitonic\n");
	else printf("Maximum Element in Bitonic Array: %d\n", *(nums + maxInBitonic(nums,n)));
}

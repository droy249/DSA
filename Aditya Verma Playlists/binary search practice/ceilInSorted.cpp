/* FIND CEILING OF AN ELEMENT IN A SORTED ARRAY:
 * 
 * Given a sorted array and a value x, the ceiling of x is the
 * smallest element in array larger than or equal to x. Write
 * efficient function to find the ceiling of x.
**/

#include <stdio.h>

const int ceilInSortedArray(const int *arr, const int &n, const int &key){
	if(key < *arr) return 0;
	if(key > arr[n - 1]) return -1;
	
	int low = 0, high = n, ans = -1;
	while(low <= high){
		const int mid = low + (high - low) / 2;
		if(arr[mid] == key) return mid;
		if(arr[mid] > key) ans = mid, high = mid - 1;
		else if(arr[mid] < key) low = mid + 1;
	}
	return ans;
}

// Driver Code
int main(){
	const int arr[] = {1, 2, 8, 10, 10, 12, 19};
	const int n = sizeof(arr) / sizeof(*arr);
	
	while(true){
		printf("Enter element to search ceiling of: ");
		int key; scanf("%d", &key);
		if(key < 0) break;
		
		const int index = ceilInSortedArray(arr, n, key);
		if (index == -1) printf("Ceiling of %d doesn't exist in array\n\n", key);
	    else printf("Ceiling of %d is %d\n\n", key, arr[index]);
	}
	printf("Exiting...\n");
}

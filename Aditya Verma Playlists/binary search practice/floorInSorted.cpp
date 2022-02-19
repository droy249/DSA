/* FIND FLOOR OF AN ELEMENT IN A SORTED ARRAY:
 * 
 * Given a sorted array and a value x, the floor of x is the
 * largest element in array smaller than or equal to x. Write
 * efficient function to find the floor of x.
**/

#include <stdio.h>

const int floorInSortedArray(const int *arr, const int &n, const int &key){
	if(key > *(arr + n - 1)) return n - 1;
	
	int low = 0, high = n, ans = -1;
	while(low <= high){
		const int mid = low + (high - low) / 2;
		if(arr[mid] == key) return mid;
		if(arr[mid] < key) ans = mid, low = mid + 1;
		else if(arr[mid] > key) high = mid - 1;
	}
	return ans;
}

// Driver Code
int main(){
	const int arr[] = {1, 2, 8, 10, 10, 12, 19};
	const int n = sizeof(arr) / sizeof(*arr);
	
	while(true){
		printf("Enter element to search floor of: ");
		int key; scanf("%d", &key);
		if(key < 0) break;
		
		const int index = floorInSortedArray(arr, n, key);
		if (index == -1) printf("Floor of %d doesn't exist in array\n\n", key);
	    else printf("Floor of %d is %d\n\n", key, arr[index]);
	}
	printf("Exiting...\n");
}

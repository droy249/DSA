/* Given a REVERSE sorted array arr[] of n elements, 
 * write a function to search a given element x in arr[].
 * 
 * Answer: Binary Search: Search a sorted array by repeatedly 
 * dividing the search interval in half. Begin with an interval 
 * covering the whole array. If the value of the search key is 
 * less than the item in the middle of the interval, narrow the 
 * interval to the lower half. Otherwise narrow it to the upper 
 * half. Repeatedly check until the value is found or the interval 
 * is empty. 
 * 
 * Time Complexity: O(log n)
 * Space Complexity: O(1)		(For interative algorithm)
 * 					 O(log n)	(For recursive algorithm)
**/

#include <iostream>

int binarySearch(const int *arr, int low, int high, const int &x){
	if(low <= high){
		const int mid = low + (high - low) / 2;
		
		if(arr[mid] == x) return mid;
		else if(x < arr[mid]) return binarySearch(arr, mid + 1, high, x);
		else return binarySearch(arr, low, mid - 1, x);
	}
	 else return -1;
}

const int binarySearch(const int *arr, const int &n, const int &x){
	int low = 0, high = n - 1;
	while (low <= high){
		const int mid = low + (high - low) / 2;
		if(x == arr[mid]) return mid;
		else if(x < arr[mid]) low = mid + 1;
		else high = mid - 1;
	}
	return -1;
}

int main(){
	const int arr[] = {100, 81, 64, 49, 36, 25, 16, 9, 4, 1, 0};
	const int n = sizeof(arr)/sizeof(arr[0]);
	 
	while(true) {
		int x; std::cin >> x;
		if(x < 0) break;
		
		const int index =
		binarySearch(arr, n, x); 
		// binarySearch(arr, 0, n - 1, x);
		if(index == -1) std::cout << "Element not found\n\n";
		else std::cout << "Element found at index " << index << "\n\n";
	}
	std::cout << "Exiting...\n";
}

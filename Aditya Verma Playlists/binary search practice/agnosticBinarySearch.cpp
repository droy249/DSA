/* PROBLEM STATEMENT: 
 * Given a sorted array of numbers, find if a given number ‘key’ 
 * is present in the array. Though we know that the array is sorted, 
 * we don’t know if it’s sorted in ascending or descending order.
 * 
 * SOLUTION: Binary Search
 * 
 * Time Complexity: O(log n)
 * Space Complexity: O(1)		(For interative algorithm)
 * 					 O(log n)	(For recursive algorithm)
 */

#include <iostream>
#include <vector>

int agnosticBinarySearch(const int *arr, int low, int high, const int &x){
	// For size of array <= 1
	if(high == 0) return *arr == x ? 0 : -1;
	
	// For size of array > 1
	if(low <= high){
		const int mid = low + (high - low) / 2;
		if(arr[mid] == x) return mid;
		else if((arr[0] < arr[1] && x < arr[mid]) || \
		(arr[0] > arr[1] && x > arr[mid])) agnosticBinarySearch(arr, low, high - 1, x);
		else agnosticBinarySearch(arr, mid + 1, high, x);
	}
	return -1;
}

const int agnosticBinarySearch(const int *arr, const int &n, const int &x){
	// For size of array <= 1
	if(n == 1) return *arr == x ? 0 : -1;
	
	// For size of array > 1
	int low = 0, high = n - 1;
	while(low <= high){
		const int mid = low + (high - low) / 2;
		if(arr[mid] == x) return mid;
		else if((arr[0] < arr[1] && x < arr[mid]) || 
		(arr[0] > arr[1] && x > arr[mid]))  high = mid - 1;
		else low = mid + 1;
	}
	return -1;
}

int main(){
	const int a[] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100};
	const int m = sizeof(a)/sizeof(a[0]);
	const int b[] = {100, 81, 64, 49, 36, 25, 16, 9, 4, 1, 0};
	const int n = sizeof(b) / sizeof(b[0]);

	int k; std::cin>>k;
	std::vector<int> v(n);
	int arr[v.size()];

	while(true){
		int x; std::cin >> x;
		if(x < 0) break;
		
		const int index = 
		// agnosticBinarySearch(a, 0, m - 1, x);
		agnosticBinarySearch(a, m, x);
		// agnosticBinarySearch(b, 0, n - 1, x);
		// agnosticBinarySearch(b, n, x);
		if(index == -1) std::cout << "Element not found\n\n";
		else std::cout << "Element found at index " << index << "\n\n";
	}
	std::cout << "Exiting...\n";
}

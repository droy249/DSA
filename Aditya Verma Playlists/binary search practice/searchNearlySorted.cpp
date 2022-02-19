/* PROBLEM:
 * Given an array which is sorted, but after sorting some elements are
 * moved to either of the adjacent positions, i.e., arr[i] may be present 
 * at arr[i+1] or arr[i-1]. Write an efficient function to search an
 * element in this array. Basically the element arr[i] can only be swapped 
 * with either arr[i+1] or arr[i-1].
 * 
 * SOLUTION: Modified binary search
 * Time Complexity: O(log n)
**/

// C++ program to find an element in an almost sorted array
#include <iostream>

/* A recursive binary search based function which returns index of x 
 * in given array arr[l..r] is present, otherwise returns -1.
 */ 
const int searchNearlySorted(const int *arr, const int &n, const int &key){
	
	int low = 0, high = n - 1;
	
	while(low <= high){
		const int mid = low + (high - low) / 2;
		
		// Check if key is present at one of the three middle positions
		if(key == arr[mid]) return mid;
		if(low < mid && key == arr[mid - 1]) return mid - 1;
		if(mid < high && key == arr[mid + 1]) return mid + 1;
		
		// If key is not found in middle positions, reduce search space accordingly
		key < arr[mid] ? high = mid - 2 : low = mid + 2;
	}
	return -1;
}

// Drive program
int main(){
	const int arr[] = {10, 3, 40, 20, 50, 80, 70};
	const int n = sizeof(arr) / sizeof(*arr);
    
    while(true){
		std::cout << "Enter element to search: ";
		int key; std::cin >> key;
		
		// Break loop if input < 0
		if(key < 0) break;
		
		// Function calling
		const int index = searchNearlySorted(arr, n, key);
		
		// Final output
		if(index == -1) std::cout << "Element not found\n\n";
		else std::cout << "Index of element is " << index << "\n\n";
	}
    std::cout << "Exiting....\n";
}

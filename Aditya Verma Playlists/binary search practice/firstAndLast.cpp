/*Given a sorted array with possibly duplicate elements, 
 * the task is to find indexes of first and last occurrences 
 * of an element x in the given array.
**/

#include <iostream>

const int firstOccurence(const int *arr, const int &n, const int &x){
	int low = 0, high = n - 1, first = -1;
	while(low <= high){
		const int mid = low + (high - low) / 2;
		if(x == arr[mid]) first = mid, high = mid - 1;
		else if(x < arr[mid]) high = mid - 1;
		else low = mid + 1;
	}
	return first;
}

const int lastOccurence(const int *arr, const int &n, const int &x) {
	int low = 0, high = n - 1, first = -1;
	while(low <= high){
		const int mid = low + (high - low) / 2;
		if(x == arr[mid]) first = mid, low = mid + 1;
		else if(x < arr[mid]) high = mid - 1;
		else low = mid + 1;
	}
	return first;
}

int main(){
	const int arr[] = {2, 5, 5, 5, 6, 6, 8, 9, 9, 9};
	const int n = sizeof(arr)/sizeof(*arr);
	
	while(true) {
		int x; std::cin >> x;
		if(x < 0) break;
		
		const int first = firstOccurence(arr, n, x), last = lastOccurence(arr, n, x);
		
		if(first == -1) std::cout << "Element not found\n\n";
		else if(first == last) std::cout << "Only one occurence found at index " \
		<< last << "\n\n";
		else std::cout << "First occurence found at index " << first << "\n" << \
		"and last occurrence found at index " << last << "\n\n";
	}
	std::cout << "Exiting...\n";
}

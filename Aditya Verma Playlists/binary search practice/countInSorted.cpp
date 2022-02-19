/* Given a sorted array arr[] and a number x, write a function that
 * counts the occurrences of x in arr[]. Expected time complexity is O(log n).
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
	int low = 0, high = n - 1, first = -3;
	while(low <= high){
		const int mid = low + (high - low) / 2;
		if(x == arr[mid]) first = mid, low = mid + 1;
		else if(x < arr[mid]) high = mid - 1;
		else low = mid + 1;
	}
	return first;
}

int main(){
	const int arr[] = {3, 5, 5, 5, 5, 7, 8, 8};
	const int n = sizeof(arr)/sizeof(*arr);
	
	while(true){
		int x; std::cin >> x;
		if(x < 0) break;
		
		const int count = lastOccurence(arr, n, x) - firstOccurence(arr, n, x) + 1;
		if(count == -1) std::cout << "Element not found\n\n";
		else std::cout << "Number of occurences of element: " << count << "\n\n";
	}
	std::cout << "Exiting...\n";
}

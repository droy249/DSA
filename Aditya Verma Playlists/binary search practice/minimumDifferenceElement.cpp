/* Given a sorted array, find the element in the array which has
 * minimum difference with the given number.
 */

#include <iostream>

template <class T> const T min(const T &a, const T &b) {return a < b ? a : b;}

int minimumDifferenceElement(int *arr, int low, int high, int key){
	// int ans = 2147483647;\
	if
	while(low + 1 < high){
		int mid = low + (high - low) / 2;
		if(arr[mid] == key) return 0;
		// ans = min(ans, abs(arr[mid] - key));
		else if(arr[mid] > key) high = mid;
		else low = mid;
	}
	return min(abs(arr[low] - key), abs(arr[high] - key));
}

int main(){
	int arr[] = {1,3,8,10,12,15};
	int n = sizeof(arr)/sizeof(*arr);

	while(true){
		int key; std::cin >> key;
		if(key < 0) break;

		std::cout << "Minimum Difference = " << minimumDifferenceElement(arr, 0, n, key) << "\n\n";
	}
	std::cout << "Exiting...\n";
}

/* Another way is to simply find the ceil and floor of the key within the given array
 * and returning the minimum among the absolute differences between the ceil and floor 
 * with the key. Refer ceilInSorted.cpp and floorInSorted.cpp
 */

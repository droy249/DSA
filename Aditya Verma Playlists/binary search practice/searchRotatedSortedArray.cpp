/* Search an element in sorted and rotated
 * array using single pass of Binary Search.
**/

#include <iostream>

/* Returns index of key in arr[l..h] if
 * key is present, otherwise returns -1
**/
int searchRotatedSortedArray(const int *arr, int l, int h, const int &key)
{
    if (l > h) return -1;
 
    const int mid = l + (h - l) / 2;
    if (arr[mid] == key) return mid;
 
    /* If arr[l...mid] is sorted */
    if (arr[l] <= arr[mid]) {
        /* As this subarray is sorted, we can quickly 
        check if key lies in half or other half */
        if (key >= arr[l] && key <= arr[mid])
            return searchRotatedSortedArray(arr, l, mid - 1, key);
        /*If key not lies in first half subarray,
           Divide other half  into two subarrays,
           such that we can quickly check if key lies
           in other half */
        return searchRotatedSortedArray(arr, mid + 1, h, key);
    }
 
    /* If arr[l..mid] first subarray is not sorted, then arr[mid... h]
    must be sorted subarray */
    if (key >= arr[mid] && key <= arr[h])
        return searchRotatedSortedArray(arr, mid + 1, h, key);
 
    return searchRotatedSortedArray(arr, l, mid - 1, key);
    
    // Iterative version
    // while(l <= h){
		// const int mid = l + (h - l) / 2;
		// arr[l] <= arr[mid] ?
			// key >= arr[l] && key <= arr[mid] ? h = mid - 1 : l = mid + 1 :
			// key >= arr[mid] && key <= arr[h] ? l = mid + 1 : h = mid = 1 ;
	// } return -1;
}
 
// Driver program
int main(){
    const int arr1[] = { 5, 6, 7, 8, 9, 10, 1, 2, 3 };
    const int n = sizeof(arr1) / sizeof(*arr1);
    
    while(true){
		std::cout << "Enter element to search: ";
		int key; std::cin >> key;
		
		// Break loop if input < 0
		if(key < 0) break;
		
		// Function calling
		const int index = searchRotatedSortedArray(arr1, 0, n - 1, key);
		
		// Final output
		if(index == -1) std::cout << "Element not found\n\n";
		else std::cout << "Index of element is " << index << "\n\n";
	}
    std::cout << "Exiting....\n";
}

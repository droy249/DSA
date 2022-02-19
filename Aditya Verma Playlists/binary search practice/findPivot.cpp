/* Consider an array of distinct numbers sorted in increasing order. 
 * The array has been rotated (clockwise) k number of times. Given such 
 * an array, find the value of k.
 * 
 * Expected Time Complexity: O(log n)
**/

#include <iostream>

int findPivot(const int *arr, int low, int high)
{
    // Base Cases
    if (high < low) return -1;
    if (high == low) return low;
 
    // Calculating the middle
    const int mid = low + (high - low) / 2;

	// Cases involving middle element
    // if (mid < high && arr[mid] > arr[mid + 1]) return mid;
    // if (mid > low && arr[mid] < arr[mid - 1]) return mid - 1;
 
    // return arr[low] >= arr[mid] ? findPivot(arr, low, mid - 1) : findPivot(arr, mid + 1, high);
	return arr[mid] < arr[high] ? findPivot(arr,low,mid) : findPivot(arr,mid+1,high);
}
 

int main(){
	const int arr[] = {4,5,6,7,0,1,2}; //{6,7,8,9,1,2,3,4,5}; 
	// {6, 8, 9, 9, 9, 2, 5, 5, 5, 6}; 
	const int n = sizeof(arr)/sizeof(*arr);
	std::cout << "Number of rotations: " << findPivot(arr, 0, n - 1) << "\n";
}

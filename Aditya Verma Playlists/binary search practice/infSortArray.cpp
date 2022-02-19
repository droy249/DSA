/* Suppose you have a sorted array of infinite numbers, how would you search 
 * an element in the array?
 * Source: Amazon Interview Experience
**/

// C++ program to demonstrate working of an algorithm that finds
// an element in an array of infinite size
#include <iostream>

int binarySearch(int *A, int low, int high, int x){
    int mid = (low + high) / 2;
    if (x == A[mid]) 
        return mid;
    else if (x < A[mid]) 
        return binarySearch(A, low,  mid - 1, x);
    else if (x > A[mid]) 
        return binarySearch(A, mid + 1,  high, x);
    else 
		return -1;
}

// function takes an infinite size array and a key to be
// searched and returns its position if found else -1.
// We don't know size of arr[] and we can assume size to be
// infinite in this function.
// NOTE THAT THIS FUNCTION ASSUMES arr[] TO BE OF INFINITE SIZE
// THEREFORE, THERE IS NO INDEX OUT OF BOUND CHECKING 
int searchInfiniteArray(int *arr, int key){
	int low = 0, high = 1;
	while(arr[high] < key){
		low = high, high <<= 1;
	}
	return binarySearch(arr, low, high, key);
}

int main(){
	int arr[100001];
	for(int i = 0; i <= 1e5; ++i) arr[i] = i;
	
	while(true){
		std::cout << "Enter the element to search :";
		int key; std::cin >> key;
		if(key < 0) break;
		
		int index = searchInfiniteArray(arr, key);
		if(index == -1) std::cout << "Element not found\n\n";
		else std::cout << "Element found at index: " << index << "\n\n";
	}
	std::cout << "Exiting...\n";
}

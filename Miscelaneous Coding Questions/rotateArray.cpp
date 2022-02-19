/* C++ program to rotate an array of size 'n' in-place 
 * 'd' number of times in both left and right directions.
 * 
 * Left Rotate <===> Rotate Anticlockwise
 * Right Rotate <===> Rotate Clockwise
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * 
 * Refer: https://leetcode.com/problems/rotate-array/discuss/54277/Summary-of-C%2B%2B-solutions
 */

#include <iostream>

int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a % b);
}

void leftRotateArray(int *arr, const int &n, const int &d);
void printLeftRotateArray(int *arr, const int &n, const int &d);
void rightRotateArray(int *arr, const int &n, const int &d);
void printRightRotateArray(int *arr, const int &n, const int &d);
void leftRotateArrayReverse(int *arr, const int &n, const int &d);
void rightRotateArrayReverse(int *arr, const int &n, const int &d);

int main(){
	int ar[] = {1,1,2,2,3,3,4,4,5,5};
	int arr[] = {1,1,2,2,3,3,4,4,5,5};
	int n = sizeof(ar)/sizeof(ar[0]), d = 4;
	
	std::cout << "\nInitial array: ";
	for(int i = 0; i < n; ++i) std::cout << ar[i] << (i == n ? "\n" : " ");
	
	/* FUNCTIONS THAT PRINT ROTATED ARRAY WITHOUT MODIFICATIONS */
	// printLeftRotateArray(arr,n,d);
	// printRightRotateArray(arr,n,d);
	
	/* 	FUNCTIONS THAT ROTATE ARRAYS IN-PLACE */	
	// leftRotateArray(ar,n,d);
	// std::cout << "\nLeft Rotated array: ";
	// for(int i = 0; i < n; ++i) std::cout << ar[i] << (i == n ? "\n" : " ");
	
	// rightRotateArray(arr,n,d);
	// std::cout << "\nRight Rotated array: ";
	// for(int i = 0; i < n; ++i) std::cout << arr[i] << (i == n ? "\n" : " ");
	
	leftRotateArrayReverse(ar,n,d);
	std::cout << "\nLeft Rotated array: ";
	for(int i = 0; i < n; ++i) std::cout << ar[i] << (i == n ? "\n" : " ");
	
	rightRotateArrayReverse(arr,n,d);
	std::cout << "\nRight Rotated array: ";
	for(int i = 0; i < n; ++i) std::cout << arr[i] << (i == n ? "\n" : " ");
	
	std::cout << std::endl << std::endl;
}

void printLeftRotateArray(int *arr, const int &n, const int &k){
	std::cout << "\nPrint Left Rotated array: ";
	for(int i = 0; i < n; ++i)
	std::cout << arr[(i < (k % n) ? n : 0) + i - (k % n)] << (i == n ? "\n" : " ");
}

void printRightRotateArray(int *arr, const int &n, const int &k){
	std::cout << "\nPrint Right Rotated array: ";
	for(int i = 0; i < n; ++i)
	std::cout << arr[(i < (k % n) ? n : 0) + i - (k % n)] << (i == n ? "\n" : " ");
}

void leftRotateArray(int* arr, const int &n, const int &d){
	for(int i = 0; i < gcd(n, d % n); ++i){
		int temp = arr[i], j = i;
		while(true){
			int k = j + (d % n);
			if(k >= n) k -= n;
			if(k == i) break;
			arr[j] = arr[k];
			j = k;
		}
		arr[j] = temp;
	}
}

void rightRotateArray(int* arr, const int &n, const int &d){
	for(int i = 0; i < gcd(n, d % n); ++i){
		int temp = arr[i], j = i;
		while(true){
			int k = j - (d % n);
			if(k < 0) k += n;
			if(k == i) break;
			arr[j] = arr[k];
			j = k;
		}
		arr[j] = temp;
	}
}

void swap(int *arr, const int &i, const int &j){
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}
 
void reverseArray(int *arr, const int &lo, const int &hi){
	for(int i{lo}, j{hi}; i < j; ++i, --j)
		swap(arr, i, j);
}

void leftRotateArrayReverse(int *arr, const int &n, const int &d){
	reverseArray(arr, 0, d - 1);
	reverseArray(arr, d, n - 1);
	reverseArray(arr, 0, n - 1);
}

void rightRotateArrayReverse(int *arr, const int &n, const int &d){
	reverseArray(arr, 0, n - 1 - d);
	reverseArray(arr, n - d, n - 1);
	reverseArray(arr, 0, n - 1);
}
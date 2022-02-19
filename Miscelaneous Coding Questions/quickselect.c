/* Quickselect is a selection algorithm to find the k-th smallest element in an unordered list.

Input: arr[] = {7, 10, 4, 3, 20, 15}, k = 3
Output: 7

Input: arr[] = {7, 10, 4, 3, 20, 15}, k = 4
Output: 10 

Video link: https://www.youtube.com/watch?v=fnbImb8lo88&list=PL-Jc9J83PIiFc7hJ5eeCb579PS8p-en4f&index=8&ab_channel=Pepcoding
Link: https://www.pepcoding.com/resources/online-java-foundation/time-and-space-complexity/quick-select-official/ojquestion
*/
#include <stdio.h>

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int nums[], const int lo, const int hi, const int pivot){
	
	/* 0 to j-2 >===> < pivot
	j to i-i >===> > pivot
	j - 1 >====> = pivot
	i to n >===> unkwown */
	int i = lo, j = lo;
	while(i <= hi) nums[i] <= pivot ? swap(&nums[i++], &nums[j++]) : ++i;
	return j - 1;
}

int quickSelect(int arr[], int lo, int hi, int k){
	int pivot = arr[hi];
	int pi = partition(arr,lo,hi,pivot);
	
	// if(k > pi) return quickSelect(arr,pi+1,hi,k);
	// else if(k < pi) return quickSelect(arr,lo,pi-1,k);
	// else return arr[k];
	
	return k == pi ? arr[pi] : k < pi ? quickSelect(arr,lo,pi-1,k) : quickSelect(arr,pi+1,hi,k);
}

int main() {
	int arr[] = {7, -2, 4, 1, 3};
	int n = sizeof(arr)/sizeof(*arr), k = 3;
	printf("The %d smallest element in given array is %d.\n", k, quickSelect(arr,0,n-1,k-1));
}
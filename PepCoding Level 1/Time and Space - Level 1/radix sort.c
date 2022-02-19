/* Write a program to implement radix sort. 

REMEMBER: Place/value wit higher precedence gets sorted LAST.

Time Complexity: O(b * n) where b is the number of digits in maximum value and n is length of array
Space Complexity: O(b + n)
(Reference Link: https://www.pepcoding.com/resources/online-java-foundation/time-and-space-complexity/radix_sort/topic#:~:text=Time%20Complexity%20%3A,type%20of%20doubts.)

Reference Link: https://www.pepcoding.com/resources/online-java-foundation/time-and-space-complexity/radix_sort/topic#:~:text=It%20is%20mainly%20used%20when%20the%20range%20of%20input%20array%20doesn%27t%20vary%20much%20and%20data%20is%20large%20like%20say%20in%20a%20competitive%20exam%20of%20100%20marks%20100000%20students%20appeared.%20In%20such%20a%20situation%20the%20range%20is%20100%20but%20100000%20is%20the%20n(length%20of%20the%20array).%20How%20do%20we%20do%20that%3F%20We%20will%20soon%20look%20into%20it.

Video Link: https://www.youtube.com/watch?v=a5e7RgCdel0&list=PL-Jc9J83PIiFc7hJ5eeCb579PS8p-en4f&index=10
 */
#include <stdio.h>

void countSort(int *arr, const int *n, const int exp){
	int count[10] = {};
	
	for(int i = 0; i < *n; ++i) ++count[arr[i] / exp % 10];
	
	for(int i = 1; i < 10; ++i) count[i] += count[i - 1];
	
	int output[*n];
	for(int i = *n - 1; i >= 0; --i) output[--count[arr[i] / exp % 10]] = arr[i];
	
	for (int i = 0; i < *n; ++i) arr[i] = output[i];
}

void radixSort(int *arr, const int *n){
	int max = *arr;
	for(int i = 1; i < *n; ++i)
		if(max < arr[i]) max = arr[i];
	
	int exp = 1; 
	while(exp < max){
		countSort(arr, n, exp);
		exp *= 10;
	}
	
	// for (int exp = 1; max/exp > 0; exp *= 10)
        // countSort(arr, n, exp);
}

void printArray(const int *nums, const int *n){
	for(int i = 0; i < *n; ++i)
		printf("%d%s", nums[i], i != *n - 1  ? ", " : "\n");
}

int main() {
	int arr[] = {213, 97, 718, 123, 37, 443, 982, 64, 375, 683, 512, 279, 23};
	const int n = sizeof(arr)/sizeof(*arr);
	printf("Array before sorting: ");
	printArray(arr,&n);
	radixSort(arr,&n);
	printf("\nArray after sorting: ");
	printArray(arr,&n);
	printf("\n");
}
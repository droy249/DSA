/* Counting sort is a sorting technique based on keys between a specific range. It works by counting the number of objects having distinct key values (kind of hashing)

Time Complexity: O(n + k) where 'n' is the number of elements in input array and 'k' is the range of input
Space Complexity: O(n + k)
Link: https://www.geeksforgeeks.org/time-complexities-of-all-sorting-algorithms/#:~:text=%C2%A0-,Count%20Sort,-%CE%A9(n%2Bk

It is mainly used when the range of input array doesn't vary much and data is large like say in a competitive exam of 100 marks 100000 students appeared. In such a situation the range is 100 but 100000 is the n(length of the array). How do we do that? We will soon look into it.
(Source : https://www.pepcoding.com/resources/online-java-foundation/time-and-space-complexity/count_sort/topic#:~:text=It%20is%20mainly%20used%20when%20the%20range%20of%20input%20array%20doesn%27t%20vary%20much%20and%20data%20is%20large%20like%20say%20in%20a%20competitive%20exam%20of%20100%20marks%20100000%20students%20appeared.%20In%20such%20a%20situation%20the%20range%20is%20100%20but%20100000%20is%20the%20n(length%20of%20the%20array).%20How%20do%20we%20do%20that%3F%20We%20will%20soon%20look%20into%20it.)

i.e. mainly used when the the range of elements is less than number of elements 

Reference Link: https://www.geeksforgeeks.org/counting-sort/#:~:text=Counting%20sort%20is%20efficient%20if%20the%20range%20of%20input%20data%20is%20not%20significantly%20greater%20than%20the%20number%20of%20objects%20to%20be%20sorted.%20Consider%20the%20situation%20where%20the%20input%20sequence%20is%20between%20range%201%20to%2010K%20and%20the%20data%20is%2010%2C%205%2C%2010K%2C%205K.
Video link: https://www.youtube.com/watch?v=p-OyKUgIrx4&list=PL-Jc9J83PIiFc7hJ5eeCb579PS8p-en4f&index=9&ab_channel=Pepcoding
*/
#include <stdio.h>
#include <stdlib.h>

void countSort(int *arr, const int *n)
{
	// First calculate the maximum and minimum elements in the array to calculate range of elements.
	int min = *arr, max = *arr;
	for(int i = 1; i < *n; ++i){
		if(arr[i] < min) min = arr[i];
		if(arr[i] > max) max = arr[i];
	}
		
	//Calculate the range
	const int range = max - min + 1;
	
	// Create a count array to store count of individual characters and initialize count array as 0
	int *count = calloc(range, sizeof(int));
	
	// Store count of each element of the array
	for(int i = 0; i < *n; ++i) ++count[arr[i] - min];
	
	// Change count[i] so that count[i] now contains actual position of this character in output array via prefix sum
	for(int i = 1; i < range; ++i) count[i] += count[i - 1];
	
	// Build the output character array
	// For stable sort we shall traverse backwards
	int *output = calloc(*n, sizeof(int));
	for(int i = *n - 1; i >= 0; --i) output[--count[arr[i] - min]] = arr[i];
	// {
      // int pos = count[arr[i] - min] - 1;
      // ans[pos] = arr[i];
      // count[arr[i] - min]--;
    // }
	
	// Copy output array to given array
	for (int i = 0; i < *n; ++i) arr[i] = output[i];

	free(count);
	free(output);
}

void printArray(const int *nums, const int *n){
	for(int i = 0; i < *n; ++i)
		printf("%d%s", nums[i], i != *n - 1  ? ", " : "\n");
}

int main() {
	int arr[] = {9,6,3,5,3,4,3,9,6,4,6,5,8,9,9};
	const int n = sizeof(arr)/sizeof(*arr);
	printf("Array before sorting: ");
	printArray(arr,&n);
	countSort(arr,&n);
	printf("\nArray after sorting: ");
	printArray(arr,&n);
	printf("\n");
}
// Count frequencies of all elements in array in O(1) extra space and O(n) time

/* Question: 
Given an unsorted array of n integers which can contain integers from 1 to n.
Some elements can be repeated multiple times and some other elements can be 
absent from the array. Count frequency of all elements that are present and 
print the missing elements.

source : https://www.geeksforgeeks.org/count-frequencies-elements-array-o1-extra-space-time/
*/

// C++ program to print frequencies of all array
// elements in O(1) extra space and O(n) time
#include<bits/stdc++.h>
using namespace std;

// Function to find counts of all elements present in
// arr[0..n-1]. The array elements must be range from
// 1 to n
void findCounts(int *arr, int n)
{
	// Traverse all array elements
	int i = 0;
	while (i<n)
	{
		// If this element is already processed,
		// then nothing to do
		if (arr[i] <= 0)
		{
			i++;
			continue;
		}

		// Find index corresponding to this element
		// For example, index for 5 is 4
		int elementIndex = arr[i]-1;

		// If the elementIndex has an element that is not
		// processed yet, then first store that element
		// to arr[i] so that we don't lose anything.
		if (arr[elementIndex] > 0)
		{
			arr[i] = arr[elementIndex];

			// After storing arr[elementIndex], change it
			// to store initial count of 'arr[i]'
			arr[elementIndex] = -1;
		}
		else
		{
			// If this is NOT first occurrence of arr[i],
			// then decrement its count.
			arr[elementIndex]--;

			// And initialize arr[i] as 0 means the element
			// 'i+1' is not seen so far
			arr[i] = 0;
			i++;
		}
	}

	printf("\nBelow are counts of all elements\n");
	for (int i=0; i<n; i++)
		printf("%d -> %d\n", i+1, abs(arr[i]));
}

// Driver program to test above function
int main()
{
	int arr[] = {2, 3, 3, 2, 5};
	findCounts(arr, sizeof(arr)/ sizeof(arr[0]));

	int arr1[] = {1};
	findCounts(arr1, sizeof(arr1)/ sizeof(arr1[0]));

	int arr3[] = {4, 4, 4, 4};
	findCounts(arr3, sizeof(arr3)/ sizeof(arr3[0]));

	int arr2[] = {1, 3, 5, 7, 9, 1, 3, 5, 7, 9, 1};
	findCounts(arr2, sizeof(arr2)/ sizeof(arr2[0]));

	int arr4[] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
	findCounts(arr4, sizeof(arr4)/ sizeof(arr4[0]));

	int arr5[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	findCounts(arr5, sizeof(arr5)/ sizeof(arr5[0]));

	int arr6[] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	findCounts(arr6, sizeof(arr6)/ sizeof(arr6[0]));

	return 0;
}

// Detailed analysis: https://www.geeksforgeeks.org/time-complexities-of-all-sorting-algorithms/#:~:text=O(1)-,Heap%20Sort,-%CE%A9(n%20log
// Gfg Link: https://www.geeksforgeeks.org/heap-sort/
// Video Link: https://youtu.be/UVW0NfG_YWA?list=PLUcsbZa0qzu3yNzzAxgvSgRobdUUJvz7p
#include <stdio.h>

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

/* Converts given complete binary tree (represented
using an array) to a binary heap from 'i' index onwards
till the last element

Time Complexity: O(log n)
Space Complexity: O(1) 		{If stack space not counted}
                                  O(log n)	{If stack space counted}
*/
// To heapify a subtree rooted with node 'i' which is an index in arr[] (n is size of heap)
void heapify(int arr[], int n, int i) {
    // Initialize largest as root
    int largest = i;

    // left = 2*i + 1
    int l = 2 * i + 1;

    // right = 2*i + 2
    int r = 2 * i + 2;

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest
    // so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr, i, largest);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Time Complexity: O(n log n) for all cases
// Space Complexity: O(1)
void heapSort(int arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; --i) {
        // Move current root to end
        swap(arr, 0, i);

        // call max heapify on the reduced heap
        heapify_down(arr, n, 0);
    }
}

void printArray(const int *nums, const int *n) {
    for (int i = 0; i < *n; ++i)
        printf("%d%s", nums[i], i != *n - 1 ? ", " : "\n");
}

int main(void) {
    int nums[] = {6, 5, 3, 1, 8, 7, 2, 4};
    const n = sizeof(nums) / sizeof(*nums);

    printf("Array before sorting: ");
    printArray(nums, &n);

    heapSort(nums, n);

    printf("\nArray after sorting: ");
    printArray(nums, &n);
    printf("\n");
}
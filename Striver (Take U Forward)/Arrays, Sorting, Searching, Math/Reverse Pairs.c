// SDE Sheet Link: https://takeuforward.org/data-structure/count-reverse-pairs/
// Video Link: https://youtu.be/S6rsAlj_iB4?list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2
// Leetcode Link: https://leetcode.com/problems/reverse-pairs/
#include <stdio.h>

int mergeAndCount(int nums[], int l, int m, int r) {
    // First define the left and right halves
    int n1 = m - l + 1;
    int n2 = r - m;

    int left[n1], right[n2];

    for (int i = 0; i < n1; ++i) left[i] = nums[l + i];
    for (int i = 0; i < n2; ++i) right[i] = nums[m + 1 + i];

    // Next calculate all the reverse pairs
    // Time Complexity: O(n1 + n2) = O(n)
    int rev_pairs = 0;
    for (int i = 0, j = 0; i < n1; ++i) {
        while (j < n2 && left[i] < 2 * right[j]) {
            ++j;
        }
        rev_pairs += j;
    }

    // Now proceed with the merge sort
    int i = 0;  // for left[]
    int j = 0;  // for right[]
    int k = l;  // for merged sorted array

    while (i < n1 && j < n2) {
        if (left[i] < right[j]) {
            nums[k++] = left[i++];
        } else {
            nums[k++] = right[j++];
        }
    }

    while (i < n1) nums[k++] = left[i++];
    while (j < n2) nums[k++] = right[j++];

    return rev_pairs;
}

int mergeSort(int nums[], int l, int r) {
    int rev_pairs = 0;

    if (l < r) {
        int m = l + (r - l) / 2;
        rev_pairs += mergeSort(nums, l, m);
        rev_pairs += mergeSort(nums, m + 1, r);
        rev_pairs += mergeAndCount(nums, l, m, r);
    }

    return rev_pairs;
}

int reversePairs(int* nums, int numsSize) {
    return mergeSort(nums, 0, numsSize - 1);
}

int main() {
    int nums[] = {1,3,2,3,1};
    int n = sizeof(nums)/ sizeof(nums[0]);

    printf("Reverse Pairs: %d\n", reversePairs(nums, n));
}
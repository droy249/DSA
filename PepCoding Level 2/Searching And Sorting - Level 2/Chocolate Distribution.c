// Question Link: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/searching-and-sorting/chocolate-distribution/ojquestion
// Video Link: https://youtu.be/50nn3bA1BT4?list=PL-Jc9J83PIiHhXKonZxk7gbEWsmSYP5kq
// Gfg Link: https://www.geeksforgeeks.org/chocolate-distribution-problem/
#include <stdio.h>
#include <stdlib.h>

// Compare function for qsort
int cmpfunc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// arr[0..n-1] represents sizes of packets
// m is number of students.
// Returns minimum difference between maximum
// and minimum values of distribution.
int findMinDiff(int arr[], int n, int m) {          // TC = O(n log n)
    // if there are no chocolates or number
    // of students is 0
    if (m == 0 || n == 0)
        return 0;

    // Sort the given packets
    qsort(arr, n, sizeof(int), cmpfunc);

    // Number of students cannot be more than
    // number of packets
    if (n < m)
        return -1;

    // Largest number of chocolates
    int min_diff = INT_MAX;

    // Find the subarray of size m such that
    // difference between last (maximum in case
    // of sorted) and first (minimum in case of
    // sorted) elements of subarray is minimum.

    for (int i = 0; i + m - 1 < n; i++) {
        int diff = arr[i + m - 1] - arr[i];
        if (diff < min_diff)
            min_diff = diff;
    }
    return min_diff;
}

int main() {
    int arr[] = {12, 4, 7, 9, 2, 23, 25, 41, 30,
                 40, 28, 42, 30, 44, 48, 43, 50};
    int m = 7;  // Number of students
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Minimum difference is %d",
           findMinDiff(arr, n, m));
    return 0;
}
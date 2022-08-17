// Question Link: https://takeuforward.org/data-structure/merge-two-sorted-arrays-without-extra-space/
// Video Link: https://youtu.be/hVl2b3bLzBw?list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2
// Gfg LInk: https://www.geeksforgeeks.org/efficiently-merging-two-sorted-arrays-with-o1-extra-space/
// Practice Link: https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1

// Leetcode Equivalent: https://leetcode.com/problems/merge-sorted-array/
#include <bits/stdc++.h>
using namespace std;

// Method 1: Swap + Insertion sort
// Time Complexity: O(n * m)
// Space Complexity: O(1)
void merge1(long long a[], long long b[], int n, int m) {
    int j = 0;
    for (int i = 0; i < n; ++i) {
        // Take first element from a[]
        // compare it with first element of second array
        // if condition match, then swap
        if (a[i] > b[j]) {
            swap(a[i], b[j]);
        }

        // Now sort the second array to
        // put the element in its correct position
        // so that next cycle can swap elements correctly
        int first = b[0];
        // insertion sort is used here
        for (int j = 0; j < m && b[j] < first; ++j) {
            b[j - 1] = b[j];
        }
        b[j - 1] = first;
    }
}

// Method 2: Gap method
// Time Complexity: O((n + m) log (n + m))
// Space Complexity: O(1)
void merge2(long long a[], long long b[], int n, int m) {
    int gap = (n + m + 1) >> 1;

    while (gap > 0) {
        int i = 0;
        int j = gap;
        while (j < (n + m)) {
            if (j < n && i < n && a[i] > a[j]) {
                swap(a[i], a[j]);
            } else if (j >= n && i < n && a[i] > b[j - n]) {
                swap(a[i], b[j - n]);
            } else if (j >= n && i >= n && b[i - n] > b[j - n]) {
                swap(b[i - n], b[j - n]);
            }
            j++;
            i++;
        }
        if (gap == 1) {
            gap = 0;
        } else {
            gap = (gap + 1) >> 1;
        }
    }
}

int main() {
    // int a[] =
}
// Video Link: https://youtu.be/kQ1mJlwW-c0?list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2
// Gfg Link: https://www.geeksforgeeks.org/counting-inversions/
// Practive Link: https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1/

// Hackerrank Link: https://www.hackerrank.com/challenges/ctci-merge-sort/problem

// Leetcode Link: https://leetcode.com/problems/count-of-smaller-numbers-after-self/
// Leetcode Link 1: https://leetcode.com/problems/global-and-local-inversions/

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n log n)
// Space Complexity: O(n)
struct MergeSortApproach {
    // Video Link: https://youtu.be/kQ1mJlwW-c0?list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&t=330
    int countInversions(int arr[], int n) {
        int temp[n];
        return mergeSort(arr, 0, n - 1, temp);
    }

    int mergeSort(int arr[], int left, int right, int temp[]) {
        int inv_count = 0;
        if (left < right) {
            int mid = left + (right - left) / 2;

            
            /* Inversion count will be the sum of inversions in
            left-part, right-part and number of inversions in
            merging */
            inv_count += mergeSort(arr, left, mid, temp);
            inv_count += mergeSort(arr, mid + 1, right, temp);
            inv_count += merge(arr, temp, left, mid + 1, right);
        }

        return inv_count;
    }

    int merge(int arr[], int temp[], int left, int mid, int right) {
        int inv_count = 0;

        int i = left;  // index for left subarray
        int j = mid;   // index for right subarray
        int k = left;  // index for resultant merged array

        /* i < mid because 
            left subarray = arr[left...mid]
            right subarray = arr[mid+1...right] */
        while (i < mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } 
            // arr[i] > arr[j]
            else {    
                temp[k++] = arr[j++];

                // Tricky and most important part
                inv_count += mid - i;
            }
        }

        while(i < mid) {
            temp[k++] = arr[i++];
        }

        while(j <= right) {
            temp[k++] = arr[j++];
        }

        //  Transfer sorted array from temp[] to arr[]
        for(int i = left; i <= right; ++i) {
            arr[i] = temp[i];
        }

        return inv_count;
    }
};

// Link: https://www.geeksforgeeks.org/counting-inversions-using-set-in-c-stl/
// Video Link: https://youtu.be/owZhw-A0yWE?t=865
// Time Complexity: O(n ^ 2)
// Space Complexity: O(1)
struct MultisetApproach {
    int countInversions(int *arr, int n) {
        int inv_count = 0;
        
        multiset<int> s;
        s.insert(arr[0]);

        for(int i = 1; i < n; ++i) {
            s.insert(arr[i]);

            // Set the iterator to first greater element than arr[i]
            // in set (Note that set stores arr[0],.., arr[i-1]
            auto it = s.upper_bound(arr[i]);
    
            // Get distance of first greater element from end
            // and this distance is count of greater elements
            // on left side of arr[i]
            inv_count += distance(it, s.end());
        }

        return inv_count;
    }
};

int main() {
    int arr[] = {5, 3, 2, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    MergeSortApproach a;
    cout << "Number of inversions (Merge Sort Approach): " << a.countInversions(arr, n) << endl;

    MultisetApproach b;
    cout << "Number of inversions (Multiset Approach): " << b.countInversions(arr, n) << endl;
}
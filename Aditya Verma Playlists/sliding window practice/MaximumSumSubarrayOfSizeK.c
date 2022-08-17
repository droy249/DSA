// Video Link: https://youtu.be/KtpqeN0Goro?list=PL_z_8CaSLPWeM8BDJmIYDaoQ5zuwyxnfj
// Gfg Practice Link: https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k/0
#include <stdio.h>

long maximumSumSubarray(int K, int* Arr, int N) {
    long sum = 0, maxSum = 0;

    for (int i = 0; i < N; ++i) {
        sum += Arr[i];
        if (i >= K) {
            sum -= Arr[i - K];
        }
        if (maxSum < sum) {
            maxSum = sum;
        }
    }

    return maxSum;
}

long adityaVermaApproach(int k, int* arr, int n) {
    int i = 0, j = 0;
    long sum = 0, maxSum = 0;

    while (j < n) {
        sum += arr[j];

        int windowSize = j - i + 1;

        // If size of window is < k, then increase j and move on
        if (windowSize < k) {
            ++j;
        } 
        
        // Else update maxSum and slide window forward;
        else {
            if (maxSum < sum) {
                maxSum = sum;
            }

            // Sliding window forward
            ++i;
            ++j;
        }
    }

    return maxSum;
}

int main() {
    int arr[] = {100, 200, 300, 400};
    const int k = 2, n = sizeof(arr) / sizeof(*arr);
    printf("Max Sum Subarray of size %d is (My Approach) : %d\n", k, maximumSumSubarray(k, arr, n));
    printf("Max Sum Subarray of size %d is (Aditya Verma Approach) : %d\n", k, maximumSumSubarray(k, arr, n));
}
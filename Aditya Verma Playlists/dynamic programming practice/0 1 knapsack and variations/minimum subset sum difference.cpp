/* Sum of subset differences
Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum. */
// Gfg Link: https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/
#include <bits/stdc++.h>
using namespace std;

// RECURSIVE
int findMinRec(int arr[], int i, int sumCalculated, int sumTotal) {
    // If we have reached last element.  Sum of one
    // subset is sumCalculated, sum of other subset is
    // sumTotal-sumCalculated.  Return absolute difference
    // of two sums.
    if (i == 0) {
        return abs((sumTotal - sumCalculated) - sumCalculated);
    }

    // For every item arr[i], we have two choices
    // (1) We do not include it first set
    // (2) We include it in first set
    // We return minimum of two choices
    return min(findMinRec(arr, i - 1, sumCalculated + arr[i - 1], sumTotal),
               findMinRec(arr, i - 1, sumCalculated, sumTotal));
}

// Returns minimum possible difference between sums
// of two subsets
int findMin(int arr[], int n) {
    // Compute total sum of elements
    int sumTotal = 0;
    for (int i = 0; i < n; i++)
        sumTotal += arr[i];

    // Compute result using recursive function
    return findMinRec(arr, n, 0, sumTotal);
}

// TABULATION - 2D
int minimumSubsetSumDifference(const int *arr, const int n) {
    // Calculate sum of all elements
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    // Create an array to store results of subproblems
    bool dp[n + 1][sum + 1];

    // Initialize first column as true. 0 sum is possible
    // with all elements.
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    // Initialize top row, except dp[0][0], as false. With
    // 0 elements, no other sum except 0 is possible
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;

    // Fill the partition table in bottom up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            // If i'th element is excluded
            dp[i][j] = dp[i - 1][j];

            // If i'th element is included
            if (arr[i - 1] <= j)
                dp[i][j] |= dp[i - 1][j - arr[i - 1]];
        }
    }

    // Initialize difference of two sums.
    int diff = INT_MAX;

    // Find the largest j such that dp[n][j]
    // is true where j loops from sum/2 to 0
    for (int j = sum / 2; j >= 0; j--) {
        
        if (dp[n][j] == true) {
            diff = sum - 2 * j;
            break;
        }
    }
    return diff;
}

// TABULATION - 1D
int minDifference(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    
    int y = sum / 2 + 1;
    // dp[i] gives whether is it possible to get i as sum of
    // elements dd is helper variable
    // we use dd to ignoring duplicates
    bool dp[y], dd[y];

    // Initialising dp and dd
    for (int i = 0; i < y; i++) {
        dp[i] = dd[i] = false;
    }

    // sum = 0 is possible
    dd[0] = true;
    for (int i = 0; i < n; i++) {
        // updating dd[k] as true if k can be formed using
        // elements from 1 to i+1
        for (int j = 0; j + arr[i] < y; j++) {
            if (dp[j])
                dd[j + arr[i]] = true;
        }
        // updating dd
        for (int j = 0; j < y; j++) {
            if (dd[j])
                dp[j] = true;
            dd[j] = false;  // reset dd
        }
    }
    // checking the number from sum/2 to 1 which is possible
    // to get as sum

    for (int i = y - 1; i >= 0; i--) {
        if (dp[i])
            return (sum - 2 * i);
        // since i is possible to form then another number
        // is sum-i
        // so mindifference is sum-i-i
    }

    return 0;
}

int main() {
    const int arr[] = {1, 5, 11, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("The minimum possible difference between any two subsets is %d\n", minimumSubsetSumDifference(arr, n));
}

// Leetcode Link: https://leetcode.com/problems/last-stone-weight-ii/
/* Subset Sum Problem(Dynamic Programming)
Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.
Example:

Input:  set[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output:  True  //There is a subset (4, 5) with sum 9  */

// Video Link: https://youtu.be/_gPcYovP7wc?list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go
// Leetcode Link: https://leetcode.com/problems/partition-equal-subset-sum/
#include <bits/stdc++.h>
using namespace std;

bool recursive(int arr[], int n, int sum) {
    if (sum == 0) {
        return true;
    }
    else if (n == 0) {
        return false;
    }

    if (arr[n - 1] <= sum) {
        return recursive(arr, n - 1, sum - arr[n - 1]) || recursive(arr, n - 1, sum);
    } else {
        return recursive(arr, n - 1, sum);
    }
}

bool bottomUp(int arr[], int n, int sum) {
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
}
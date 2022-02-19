/* (Count of) Subset Sum Problem(Dynamic Programming)
Given an array of non-negative integers, and a value sum, determine the number of subsets of the given array with sum equal to given sum.

Example:
Input:  arr[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output: 2
*/
#include <stdio.h>

int countOfSubsets(const int nums[], const int n, const int sum) {
	int dp[n + 1][sum + 1];
	
	for(int i = 0; i <= n; ++i)
		for (int s = 0; s <= sum; ++s) 
			dp[i][s] = !s ? 1 : !i ? 0 : nums[i-1] > s ? dp[i-1][s] : dp[i-1][s - nums[i-1]] + dp[i-1][s];
		
	return dp[n][sum];
}

int main() {
	const int nums[] = {2, 3, 5, 6, 8, 10}, n = sizeof(nums) / sizeof(*nums), sum = 10;
	// printf("%s",checkSubsetExists_(nums, n, sumue) ? "\nYes\n" : "\nNo\n");
	printf("Number of subsets with sum %d = %d.\n", sum, countOfSubsets(nums, n, sum));
}
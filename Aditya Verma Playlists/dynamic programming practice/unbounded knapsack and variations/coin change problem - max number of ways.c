/* Coin Change Problem Maximum Number of ways
Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change? The order of coins doesn’t matter.
Example:
for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4.

Reference Link: https://youtu.be/I4UR2T6Ro3w
Problem Link: https://leetcode.com/problems/coin-change-2/
 */
#include <stdio.h>

int coinChangeMaxWays(const int *coins, const int n, const int sum) {
	int dp[n+1][sum+1];
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= sum; ++j)
			dp[i][j] = !j ? 1 : !i ? 0 : coins[i-1] > j ? dp[i-1][j] : dp[i-1][j] + dp[i][j-coins[i-1]];
	return dp[n][sum];
}

// This is a space-optimized version using 1D array
// Reference Link: https://youtu.be/l_nR5X9VmaI
int coinChangeMaxWaysOptimized(const int *coins, const int n, const int sum){
	int dp[sum+1];
	for(int i = 0; i <= sum; ++i) dp[i] = !i ? 1 : 0;
	for(int i = 0; i < n; ++i)
		for(int j = coins[i]; j <= sum; ++j)
			dp[j] += dp[j - coins[i]];
	return dp[sum];
}

int main() {
	const int coins[] = {2,3,5}, n = sizeof(coins)/sizeof(*coins), sum = 7;
	printf("Maximum number of combinations to obtain sum of %d is %d.\n", sum, coinChangeMaxWays(coins,n,sum));
	printf("Maximum number of combinations to obtain sum of %d is %d.\n", sum, coinChangeMaxWaysOptimized(coins,n,sum));
}
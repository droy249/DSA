/* Coin Change Problem Minimum Numbers of coins
Given a value V, if we want to make change for V cents, and we have infinite supply of each of C = { C1, C2, .. , Cm} valued coins, what is the minimum number of coins to make the change?
Example:

Input: coins[] = {25, 10, 5}, V = 30
Output: Minimum 2 coins required
We can use one coin of 25 cents and one of 5 cents 

Reference Link: https://youtu.be/I-l6PBeERuc
Problem Link: https://leetcode.com/problems/coin-change/
*/
#include <stdio.h>
#include <limits.h>
#define min(a,b) a < b ? a : b

int coinChangeMinCoins(const int *coins, const int coinsSize, const int amount){
	// int dp[n+1][sum+1];
	
	// for(int i = 0; i <= sum; ++i) dp[0][i] = INT_MAX - 1;
	// for(int i = 1; i <= n; ++i) dp[i][0] = 0;
	// for(int i = 1; i <= sum; ++i) dp[1][i] = i % coins[0] ? dp[0][i] : i / coins[1];
	
	// for(int i = 2; i <= n; ++i)
		// for(int j = 1 ; j <= sum; ++j)
			// dp[i][j] = coins[i-2]<= j ? min(1 + dp[i][j-coins[i-2]], dp[i-1][j]) : dp[i-1][j];
		
	// return dp[n][sum];
	int dp[coinsSize + 1][amount + 1];
    
    for(int i = 0; i <= coinsSize; ++i)
        for(int j = 0; j <= amount; ++j)
            dp[i][j] = !i ? INT_MAX - 1 : !j ? 0 : coins[i-1] <= j ? min(dp[i-1][j], 1 + dp[i][j-coins[i-1]]) : dp[i-1][j];
    
    return dp[coinsSize][amount] == INT_MAX - 1 ? -1 : dp[coinsSize][amount];
}

int main() {
	const int coins[] = {5,10,25}, n = sizeof(coins)/sizeof(*coins), sum = 30;
	const int ans = coinChangeMinCoins(coins,n,sum);
	if(ans == -1) printf("It is not possible the sum %d from given array", sum);
	else printf("Minimum number of coins to obtain sum of %d is %d.\n", sum, ans);
}
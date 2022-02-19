/* Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or don’t pick it (0-1 property). */
#include <stdio.h>
#define max(a,b) a > b ? a : b

int recursive01Knapsack(const int wt[], const int val[], const int n , const int w) {
    return !n || !w ? 0 : wt[n-1] > w ? recursive01Knapsack(wt, val, n - 1, w) : max(val[n-1] + recursive01Knapsack(wt, val, n - 1, w - wt[n-1]), recursive01Knapsack(wt, val, n - 1, w));
}

int memo[10001][10001];
int memoization01Knapsack(const int wt[], const int val[], const int n , const int w){
    if(!n || !w) memo[n][w] = 0;
    else if(wt[n-1] > w) memo[n][w] = memoization01Knapsack(wt,val,n-1,w);
	else memo[n][w] = max(val[n-1] + memoization01Knapsack(wt,val,n-1,w-wt[n-1]), memoization01Knapsack(wt,val,n-1,w));
	return memo[n][w];
}

int tabulation01Knapsack(const int wt[], const int val[], const int n , const int w) {
    int dp[n + 1][w + 1];
	
    for(int i = 0; i <= n; ++i) 
        for(int j = 0; j <= w; ++j) 
			dp[i][j] = !i || !j ? 0 : wt[i-1] > j ? dp[i-1][j] : max(dp[i-1][j], val[i-1] + dp[i-1][j - wt[i-1]]);
    
    return dp[n][w];
}

int main() {
    
    const int weights[] = {23, 26, 20, 18, 32, 27, 29, 26, 30, 27};				//0/1 => 1270
    const int values[] = {505, 352, 458, 220, 354, 414, 498, 545, 473, 543};	//unbounded =>1468
    const int n = sizeof(values)/sizeof(values[0]);
    const int maxWeight = 67;
    
	// Recursive approach
	printf("Recursive knapsack = %d\n", recursive01Knapsack(weights, values, n, maxWeight));
    
	// Memoization approach
	printf("Memoized knapsack = %d\n", memoization01Knapsack(weights, values, n, maxWeight));    // 1270
    
	// Tabulation approach
	printf("Tabulated knapsack = %d\n", tabulation01Knapsack(weights, values, n, maxWeight));
}
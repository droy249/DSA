/* Unbounded Knapsack (Repetition of items allowed)
 Given a knapsack weight W and a set of n items with certain value vali and weight wti, we need to calculate minimum amount that could make up this quantity exactly. This is different from classical Knapsack problem, here we are allowed to use unlimited number  of instances of an item.
Examples:

Input : W = 100
       val[]  = {1, 30}
       wt[] = {1, 50}
Output : 100
There are many ways to fill knapsack.
1) 2 instances of 50 unit weight item.
2) 100 instances of 1 unit weight item.
3) 1 instance of 50 unit weight item and 50
   instances of 1 unit weight items.
We get maximum value with option 2. */

#include <stdio.h>
#define max(a,b) a > b ? a : b



int recursiveUnboundedKnapsack(const int wt[], const int val[], const int n , const int w) {
    return !n || !w ? 0 : wt[n-1] > w ? recursiveUnboundedKnapsack(wt, val, n - 1, w) : max(val[n-1] + recursiveUnboundedKnapsack(wt, val, n, w - wt[n-1]), recursiveUnboundedKnapsack(wt, val, n - 1, w));
}

// Memoized unbounded knapsack
// Time Complexity: O(n * w)
// Space Complexity: O(n * W) + Recursion Stack Space 
int memo[10001][10001];
int memoizationUnboundedKnapsack(const int wt[], const int val[], const int n , const int w) {
    if(!n || !w) memo[n][w] = 0;
    else if(wt[n-1] > w) memo[n][w] = memoizationUnboundedKnapsack(wt,val,n-1,w);
	else memo[n][w] = max(val[n-1] + memoizationUnboundedKnapsack(wt,val,n,w-wt[n-1]), memoizationUnboundedKnapsack(wt,val,n-1,w));
	return memo[n][w];
}

// Tabulation unbounded knapsack
// Time Complexity: O(n * w)
// Space Complexity: O(n * w)
int tabulationUnboundedKnapsack(const int wt[], const int val[], const int n , const int w) {
    int dp[n + 1][w + 1];
	
    for(int i = 0; i <= n; ++i) 
        for(int j = 0; j <= w; ++j) 
			dp[i][j] = !i || !j ? 0 : wt[i-1] > j ? dp[i-1][j] : max(dp[i-1][j], val[i-1]+dp[i][j - wt[i-1]]);
    
    return dp[n][w];
}

// Optimized tabulation unbounded knapsack
// Time Complexity: O(n * w)
// Space Complexity: O(w)
int tabulationUnboundedKnapsackOptimized(const int wt[], const int val[], const int n , const int w) {
	int dp[w + 1] = {0};
	
	for(int i = 0; i <= w; ++i) 
        for(int j = 0; j < n; ++j)
			if(wt[j-1] <= i)
				dp[i] = max(dp[i], val[j-1] + dp[i - wt[j-1]]);
	
	return dp[w];
}

int main() {
    
    const int weights[] = {23, 26, 20, 18, 32, 27, 29, 26, 30, 27};				//0/1 => 1270
    const int values[] = {505, 352, 458, 220, 354, 414, 498, 545, 473, 543};	//unbounded => 1468
    const int n = sizeof(values)/sizeof(values[0]);
    const int maxWeight = 67;
    
	// Recursive approach
	printf("Recursive unbounded knapsack = %d\n", recursiveUnboundedKnapsack(weights, values, n, maxWeight));
    
	// Memoization approach
	printf("Memoized unbounded knapsack = %d\n", memoizationUnboundedKnapsack(weights, values, n, maxWeight));
    
	// Tabulation approach
	printf("Tabulated unbounded knapsack = %d\n", tabulationUnboundedKnapsack(weights, values, n, maxWeight));
	
	// Space Optimized Tabulation approach
	printf("Optimized tabulated unbounded knapsack = %d\n", tabulationUnboundedKnapsackOptimized(weights, values, n, maxWeight));
}
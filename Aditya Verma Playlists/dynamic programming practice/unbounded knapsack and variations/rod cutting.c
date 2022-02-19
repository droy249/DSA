/* Rod Cutting Problem
Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. Determine the  maximum value obtainable by cutting up the rod and selling the pieces. 

Example: 
if length of the rod is 8 and the values of different pieces are given as following, then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6)

length |  1  |  2  |  3  |  4  |  5   |  6  |  7  |  8  |
---------------------------------------------------------
price  |  1  |  5  |  8  |  9  |  10  |  17 |  17 |  20  |
*/
#include <stdio.h>
#define max(a,b) a > b ? a : b

int rodCutting(const int wt[], const int val[], const int n){
	int dp[n + 1][n + 1];
	
    for(int i = 0; i <= n; ++i) 
        for(int j = 0; j <= n; ++j) 
			dp[i][j] = !i || !j ? 0 : wt[i-1] > j ? dp[i-1][j] : max(dp[i-1][j], val[i-1] + dp[i][j - wt[i-1]]);
    
    return dp[n][n];
}

int main() {			//1 2 3 4 5  6  7  8
	const int prices[] = {1,5,8,9,10,17,17,20}, n = sizeof(prices)/sizeof(*prices);
	int length[n];
	for(int i = 0; i < n; ++i) length[i] = i + 1;
	printf("Maximum possible price  is $%d.\n",rodCutting(length,prices,n));
}
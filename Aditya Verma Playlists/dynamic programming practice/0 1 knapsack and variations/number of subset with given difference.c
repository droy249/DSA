

#include <stdio.h>

int solve(const int *nums, const int n, const int diff){
	int sum = 0;
	for(int i = 0 ; i < n; ++i) sum += nums[i];
	
	int s = diff + sum >> 1;
	
	int dp[n + 1][s + 1];
	// for(int i = 0; i < n; ++i) dp[i][0] = 0; 
	// for(int i = 0; i < s; ++i) dp[0][i] = 1;
	
	// for(int i = 1; i <= n; ++i) 
		// for(int j = 1; j <= s; ++j)
			// dp[i][j] += arr[i - 1] <= s ? dp[i][s - arr[i - 1]] : 0;
	
	for(int i = 0; i <= n; ++i)
		for (int j = 0; j <= s; ++j) 
			dp[i][j] = !j ? 1 : !i ? 0 : nums[i-1] > j ? dp[i-1][j] : dp[i-1][j - nums[i-1]] + dp[i-1][j];
		
	return dp[n][s];
}

int main(){
	const int arr[] = {1,2,3,2}, diff = 1, n = sizeof(arr)/sizeof(arr[0]);
	printf("NUmber of subsets with difference of %d are %d.\n", diff, solve(arr, n, diff));
}
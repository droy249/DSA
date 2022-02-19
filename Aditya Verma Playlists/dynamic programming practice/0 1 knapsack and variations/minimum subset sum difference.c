/* Sum of subset differences
Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum. */
#include <stdio.h>

int minimumSubsetSumDifference(const int *arr, const int n) {
	int sum = 0;
	for(int i = 0; i < n; ++i) sum += arr[i];
	
	int dp[n + 1][sum + 1];
	// for (int i = 0; i <= n; i++) dp[i][0] = 1;
	// for(int i = 1; i <= sum; ++i) dp[0][i] = 0;
	
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= sum; ++j)
			dp[i][j] = !j ? 1 : !i ? 0 :arr[i - 1] > j ? dp[i - 1][j] : dp[i - 1][j] | dp[i - 1][j - arr[i - 1]];
	
	for(int j = sum >> 1; j >= 0; --j)
		if(dp[n][j])
			return sum - 2 * j;
	
	return 0;
}

int main() {
	const int arr[] = {1,5,11,6}, n = sizeof(arr)/sizeof(arr[0]);
	printf("The minimum possible difference between any two subsets is %d\n", minimumSubsetSumDifference(arr,n));
}

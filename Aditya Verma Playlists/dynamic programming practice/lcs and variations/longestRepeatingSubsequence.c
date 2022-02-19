/* Longest Repeating Subsequence
Given a string, print the longest repeating subsequence such that the two subsequence don’t have same string character at same position, i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.
Example:
Input: str = "aab"
Output: "a"
The two subsequence are 'a'(first) and 'a' (second). Note that 'b' cannot be considered as part of subsequence as it would be at same index in both */
#include <stdio.h>
#define max(a,b) a > b ? a : b

void longestRepeatingSubsequence(const char *s, const int n){
	int dp[n+1][n+1];
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= n; ++j)
			dp[i][j] = !i || !j ? 0 : s[i-1] == s[j-1] && i != j ? 1 + dp[i-1][j-1] : max(dp[i][j-1],dp[i-1][j]);
	
	int index = dp[n][n];
	char lrs[index+1];
	lrs[index] = '\0';
	
	int i = n, j = n;
	while(i && j)
		dp[i][j] == dp[i-1][j-1] + 1 ? lrs[--index] = s[--i], --j : dp[i][j] == dp[i-1][j] ? --i : --j;
	
	printf("The longest repeating subsequence of \"%s\" is \"%s\" of length %d.\n", s, lrs, dp[n][n]);
}

int main(){
	char s[] = "aaadddefgg";
	longestRepeatingSubsequence(s, sizeof(s) - 1);
}
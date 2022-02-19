/* Given two strings str1 and str2, find the shortest string that has both str1 and str2 as subsequences.
 * Input: str1 = "geek",  str2 = "eke"  Output: "geeke"
 */

#include <stdio.h>
#define max(a,b) a > b ? a : b

void shortestCommonSubsequence(const char *s, const char *t, const int n, const int m) {
	int dp[n+1][m+1];
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= m; ++j)
			dp[i][j] = !i || !j ? 0 : s[i-1] == t[j-1] ? 1 + dp[i-1][j-1] : max(dp[i-1][j], dp[i][j-1]);
	
	int index = m + n - dp[n][m];
	char lcs[index+1];
	lcs[index] = '\0';
	
	int i = n, j = m;
	while(i && j)
		lcs[--index] = s[i-1] == t[j-1] ? s[--j, --i] : dp[i-1][j] > dp[i][j-1] ? s[--i] : t[--j];
	
	while(i)
		lcs[--index] = s[--i];
	
	while(j)
		lcs[--index] = t[--j];

	printf("Shortest common supersequence of \"%s\" and \"%s\" is \"%s\" of length %d\n", s, t, lcs, n + m - dp[n][m]);
	// printf(" %d\n", n + m - dp[n][m]);
}

int main() {
	char s[] = "abcde", t[] = "defgh";
	shortestCommonSubsequence(s,t, sizeof(s) - 1, sizeof(t) - 1);
}
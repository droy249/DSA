/* Given two strings a and b, check if a is subsequence of b.
*/
#include <stdio.h>
#define max(a, b) a > b ? a : b

int sequencePatternMatching(const char *s, const char *t, const int n, const int m) {
	int dp[n+1][m+1];
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= m; ++j)
			dp[i][j] = !i || !j ? 0 : s[i-1] == t[j-1] ? 1 + dp[i-1][j-1] : max(dp[i-1][j], dp[i][j-1]);
	fprintf(stderr,"%d %d %d\n",n,m,dp[n][m]);
	return n == dp[n][m];
}

int main() {
	const char a[] = "axy", b[] = "adxdy";
	printf("\"%s\" is %s a subsequence of \"%s\".\n", a, sequencePatternMatching(a,b,sizeof(a)-1,sizeof(b)-1) ? "\b" : "not", b);
}
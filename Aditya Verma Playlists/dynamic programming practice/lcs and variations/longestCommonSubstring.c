#include <stdio.h>

const int max(const int a, const int b) { return a > b ? a : b; }
const int min(const int a, const int b) { return a < b ? a : b; }

const int longestCommonSubstring(const char* s, const char *t) {
	int n = sizeof(s) - 1, m = sizeof(t) - 1;
	int	dp[n + 1][m + 1], result = 0;
	// fprintf(stderr, "\n%d %d\n", n, m);
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= m; ++j)
			dp[i][j] = !i || !j ? 0 : s[i-1] == t[j-1] ? 1 + dp[i-1][j-1] : 0, result = max(result, dp[i][j]);
	return result;
}

int main() {
	const char *s = "yiudevrup", *t = "dkjoievarsi";
	printf("Length of longest common substring is %d\n", longestCommonSubstring(s,t));
}
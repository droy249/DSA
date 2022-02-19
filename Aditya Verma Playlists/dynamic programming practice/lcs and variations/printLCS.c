/* Given two sequences, print the longest subsequence present in both of them.
 * Example:
 * LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3. 
 */
#include <stdio.h>
#define max(a,b) (((a) > (b)) ? (a) : (b))

void printLCS(const char *s, const char *t, const int n, const int m) {
	int dp[n+1][m+1];
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= m; ++j)
			dp[i][j] = !i || !j ? 0 : s[i-1] == t[j-1] ? 1 + dp[i-1][j-1] : max(dp[i-1][j], dp[i][j-1]);
	
	int index = dp[n][m];
	char lcs[index+1];
	lcs[index] = '\0';
	
	int i = n, j = m;
	while(i && j)
		s[i-1] == t[j-1] ? lcs[--index] = s[--i], --j : dp[i-1][j] > dp[i][j-1] ? --i : --j;

	printf("Longest common subsequence of \"%s\" and \"%s\" is \"%s\"\n", s, t, lcs);
	
}

int main() {
	char s[] = "AGGTAB", t[] = "GXTXAYB";
	printLCS(s,t, sizeof(s) - 1, sizeof(t) - 1);
}
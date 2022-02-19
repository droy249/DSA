/* Given two sequences, find the length of longest subsequence
 * present in both of them. A subsequence is a sequence that 
 * appears in the same relative order, but not necessarily contiguous.
*/
#include <stdio.h>
#include <string.h>
#define max(a,b) a > b ? a : b

int recursive(const char *s, const char *t, size_t n, size_t m) {
	return !n || !m ? 0 : s[n-1] == t[m-1] ? 1 + recursive(s,t,n-1,m-1) : max(recursive(s,t,n-1,m), recursive(s,t,n,m-1));
}

// Giving wrong answer idk why :"(
// int memoization(int memo[10001][10001], const char *s, const char *t, size_t n, size_t m) {
	// if(!n || !m) return 0;
	// if(memo[n-1][m-1] != -1) goto a;
	// memo[n-1][m-1] = s[n-1] == t[m-1] ? 1 + memoization(memo,s,t,n-1,m-1)
	// : max(memoization(memo,s,t,n-1,m), memoization(memo,s,t,n,m-1));
	// a: return memo[n-1][m-1];
// }

int tabulation(const char *s, const char *t) {
	int n = strlen(s), m = strlen(t), dp[n + 1][m + 1];
	// fprintf(stderr, "\n%d %d\n", n, m);
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= m; ++j)
			dp[i][j] = !i || !j ? 0 : s[i-1] == t[j-1] ? 1 + dp[i-1][j-1] : max(dp[i-1][j], dp[i][j-1]);
	return dp[n][m];
}

int main() {
	const char *a = "abcde", *b = "ace";
	// fprintf(stderr, "\n%zu %zu\n", strlen(a), strlen(b));
	printf("Recursive on '%s' and '%s': %d\n", a, b, recursive(a,b,strlen(a),strlen(b)));
	
	const char *s = "pmjghexybyrgzczy", *t = "hafcdqbgncrcbihkd";
	
	// int memo[10001][10001];
	// memset(memo, -1	, sizeof memo);
	// printf("Top-Down on '%s' and '%s': %d\n", s, t, memoization(memo,a,b,strlen(a),strlen(b)));
	
	printf("Bottom-Up on '%s' and '%s': %d\n", s, t, tabulation(s,t));
}
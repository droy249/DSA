/* Minimum number of deletions to make a string palindrome
   Given a string of size ‘n’. The task is to remove or delete minimum number of characters from the string so that the resultant string is palindrome.
   
   Input : aebcbda
   Output : 2
   Remove characters 'e' and 'd' 
   Resultant string will be 'abcba' which is a palindromic string
 */
#include <stdio.h>
#include <string.h> 
#define max(a,b) a > b ? a : b

int minimumDeletionsToMakeLPS(char *s) {
	const int n = strlen(s);
	char *t = strrev(s);
	int dp[n+1][n+1];
	
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= n; ++j)
			dp[i][j] = !i || !j ? 0 : s[i-1] == t[j-1] ? 1 + dp[i-1][j-1] : max(dp[i-1][j], dp[i][j-1]);
	
	return n - dp[n][n];
}

int main() {
	char s[] = "agbcba";
	printf("Minimum Number of deletions to turn \"%s\" into its longest palindromic subsequence is %d\n\n", s, minimumDeletionsToMakeLPS(s));
}
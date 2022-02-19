/* Given a sequence, find the length of the longest palindromic subsequence in it.
 * Example :
 * Input:"bbbab"
 * Output:4
 */
#include <iostream>
#include <string> 
#define max(a,b) a > b ? a : b

int longestPalindromicSubsequence(const std::string &s, const std::string &t) {
	const int n = s.length();
	// char *t = strrev(s);
	std::cout << std::endl << t << " " << n << std::endl;
	int dp[n+1][n+1];
	
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= n; ++j)
			dp[i][j] = !i || !j ? 0 : s[i-1] == t[j-1] ? 1 + dp[i-1][j-1] : max(dp[i-1][j], dp[i][j-1]);
	
	return dp[n][n];
}

int main() {
	std::string s("agbcba"), t(s.rbegin(), s.rend());
	std::cout << "Length of longest palindromic subsequence of " << s << " is " << longestPalindromicSubsequence(s,t) << std::endl;
}
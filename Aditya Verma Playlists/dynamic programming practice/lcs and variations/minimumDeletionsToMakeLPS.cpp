/* Minimum number of deletions to make a string palindrome
   Given a string of size ‘n’. The task is to remove or delete minimum number of characters from the string so that the resultant string is palindrome.
   
   Input : aebcbda
   Output : 2
   Remove characters 'e' and 'd' 
   Resultant string will be 'abcba' which is a palindromic string
   
   Exact same as : Minimum number of insertions to make a string palindrome
   Given a string, find the minimum number of characters to be inserted to form Palindrome string out of given string

   Examples:
   ab: Number of insertions required is 1. bab
   aa: Number of insertions required is 0. aa
 */
#include <iostream>
#include <string> 
#define max(a,b) a > b ? a : b

int minimumDeletionsToMakeLPS(const std::string &s, const std::string &t) {
	const int n = s.length();
	// char *t = strrev(s);
	// std::cout << std::endl << t << " " << n << std::endl;
	int dp[n+1][n+1];
	
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= n; ++j)
			dp[i][j] = !i || !j ? 0 : s.at(i-1) == t.at(j-1) ? 1 + dp[i-1][j-1] : max(dp[i-1][j], dp[i][j-1]);
	
	return n - dp[n][n];
}

int main() {
	std::string s("agbcba"), t(s.rbegin(), s.rend());
	std::cout << "Minimum Number of deletions to convert \"" << s << "\" to a palindrome is " << minimumDeletionsToMakeLPS(s,t) << std::endl;
}
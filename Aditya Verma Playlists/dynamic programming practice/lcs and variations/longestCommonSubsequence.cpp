/* Given two sequences, find the length of longest subsequence
 * present in both of them. A subsequence is a sequence that 
 * appears in the same relative order, but not necessarily contiguous.
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int max(const int &a, const int &b) { return a > b ? a : b; }

int recursive(const string &s, const string &t, size_t i = 0, size_t j = 0) {
	return i == s.size() or j == t.size() ? 0 : s.at(i) == t.at(j) ? 1 + recursive(s,t,i+1,j+1) : max(recursive(s,t,i+1,j), recursive(s,t,i,j+1));
}

int memoization(vector<vector<int>> &memo, string &s, string &t, size_t i = 0, size_t j = 0) {
	if(i == s.size() or j == t.size()) return 0;
	if(memo.at(i).at(j) != -1) return memo.at(i).at(j);
	memo.at(i).at(j) = s.at(i) == t.at(j) ? 1 + memoization(memo,s,t,i+1,j+1) : max(memoization(memo,s,t,i+1,j), memoization(memo,s,t,i,j+1));
	return memo.at(i).at(j);
}

int tabulation(const string &s, const string &t){
	int n(s.size()), m(t.size()), dp[n + 1][m + 1];
	for(int i{0}; i <= n; ++i)
		for(int j{0}; j <=m; ++j)
			dp[i][j] = !i or !j ? 0 : s.at(i-1) == t.at(j-1) ? 1 + dp[i-1][j-1] : max(dp[i-1][j], dp[i][j-1]);
	return dp[n][m];
}

string print

int main() {
	string a("abcde"), b("ace");
	cout << "Recursive on '" << a << "' and '" << b << "': " << recursive(a,b) << endl;
	
	string s("pmjghexybyrgzczy"), t("hafcdqbgncrcbihkd");
	
	vector<vector<int>> memo(10001, vector<int>(10001,-1));
	cout << "Top-Down on '" <<  s << "' and '" << t << "': " << memoization(memo,a,b) << endl;
	
	cout << "Bottom-Up on '" << s << "' and '" << t << "': " << tabulation(s,t) << endl;
}
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
// template <class T> const T &max(const T &a, const T &b) {return a > b ? a : b;}

string printLCS(const string s, const string t) {
	int n{s.length()}, m{t.length()}, dp[n+1][m+1];
	for(int i{0}; i <= n; ++i)
		for(int j{0}; j <= m; ++j)
			dp[i][j] = !i or !j ? 0 : s.at(i-1) == t.at(j-1) ? 1 + dp[i-1][j-1] : max(dp[i-1][j], dp[i][j-1]);
	
	string ans;
	for(int i{n}, j{m}; i > 0 and j > 0;) {
		if(s.at(i-1) == t.at(j-1)){
			ans.push_back(s.at(i-1));
			--i,--j;
		} else 
			dp[i-1][j] > dp[i][j-1] ? --i : --j;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main() {
	string s("abcdgh"), t("aedfhr");
	cout << "Longest common subsequence of " << s << " and  " << t << " is: " << printLCS(s,t);
}
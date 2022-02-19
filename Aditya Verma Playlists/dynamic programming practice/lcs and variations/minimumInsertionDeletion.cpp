#include <iostream>
#include <vector>
#define max(a,b) a>b?a:b

std::vector<int> minimumInsertionsDeletions(const std::string &s, const std::string &t) {
	int n(s.size()), m(t.size()), dp[n+1][m+1];
	for(int i{}; i <= n; ++i)
		for(int j{}; j <= m; ++j)
			dp[i][j] = !i or !j ? 0 : s.at(i-1) == t.at(j-1) ? 1 + dp[i-1][j-1] : max(dp[i-1][j], dp[i][j-1]);
	return {n - dp[n][m], m - dp[n][m]};
}

int main() {
	std::string a("intention"), b("execution");
	std::vector<int> ans = minimumInsertionsDeletions(a,b);
	std::cout << "The minimum number of insertions to convert " << a << " to " << b << " is " << ans.front() << " and deletions is " << ans.back() << "." << std::endl;
}
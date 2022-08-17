// Video Link: https://youtu.be/Lav6St0W_pQ?list=PL_z_8CaSLPWeM8BDJmIYDaoQ5zuwyxnfj
// Gfg Link: https://www.geeksforgeeks.org/find-the-longest-substring-with-k-unique-characters-in-a-given-string/
// Practice Link: https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1/
#include <bits/stdc++.h>
using namespace std;

int longestKSubstr(string s, int k) {
    unordered_map<char, int> mp;

    int ans = -1;
    int i = 0, j = 0;

    while (j < s.length()) {
        mp[s[j]]++;

        if (mp.size() < k) {
            ++j;
        } else if (mp.size() == k) {
            ans = max(ans, j - i + 1);
            ++j;
        } else {
            while (mp.size() > k) {
                mp[s[i]]--;
                if (mp[s[i]] == 0) {
                    mp.erase(s[i]);
                }
                ++i;
            }

            if (mp.size() == k) {
                ans = max(ans, j - i + 1);
            }

            ++j;
        }
    }

    return ans;
}

int main() {
    cout << "Length of longest substring with k characters: " << longestKSubstr("aaaa", 3) << "\n";
}
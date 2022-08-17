// Video Link: https://youtu.be/L6cffskouPQ?list=PL_z_8CaSLPWeM8BDJmIYDaoQ5zuwyxnfj
// Leetcode Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include <bits/stdc++.h>
using namespace std;

int adityaVermaApproach(string s) {
    unordered_map<char, int> mp;
    int ans = 0;

    // int i = 0, j = 0;
    for (int i = 0, j = 0; j < s.length(); ++j) {
        mp[s[j]]++;

        // if (mp.size() < j - i + 1) {
            while (mp.size() < j - i + 1) {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                    mp.erase(s[i]);
                i++;
            }
            // j++;
        // }
        
        if (mp.size() == j - i + 1)  // HERE YOU CAN ELSE AS WELL !!
        {
            ans = max(ans, j - i + 1);
            // j++;
        }

        // ++j; 
    }
    return ans;
}

int lengthOfLongestSubstring(string s) {
    unordered_set<char> mp;
    int ans = 0;

    int i = 0, j = 0;
    while (j < s.length()) {
        // if (mp.find(s[j]) != mp.end()) {
            while (mp.find(s[j]) != mp.end()) {
                mp.erase(s[i]);
                ++i;
            }
        // }
        mp.insert(s[j]);
        ans = max(ans, (int)mp.size());
        ++j;
    }

    return ans;
}

int main() {
    string s{"pwwdew"};
    cout << "\nLongest Substring Without Repeating Characters: " << adityaVermaApproach(s) << "\n";
}
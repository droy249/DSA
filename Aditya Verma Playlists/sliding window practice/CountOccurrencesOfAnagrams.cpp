// Video Link: https://youtu.be/MW4lJ8Y0xXk?list=PL_z_8CaSLPWeM8BDJmIYDaoQ5zuwyxnfj
// Gfg Practice Link: https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1
#include <bits/stdc++.h>
using namespace std;

int search(string pat, string txt) {
    unordered_map<char, int> mp;
    int ans = 0;

    // storing the occ. of string pat in the map
    for (auto &x : pat) {
        mp[x]++;
    }

    int countOfDistinctCharacters = mp.size();  // number of distinct characters
    int k = pat.size();                         // window size
    int i = 0, j = 0;                           // end points of window

    while (j < txt.size()) {
        // calculation part
        if (mp.find(txt[j]) != mp.end()) {
            mp[txt[j]]--;
            if (mp[txt[j]] == 0) {
                countOfDistinctCharacters--;
            }
        }

        // window length not achived yet
        if (j - i + 1 < k) {
            j++;
        }

        // window length achived, find ans and slide the window
        else if (j - i + 1 == k) {
            // finding the ans
            if (countOfDistinctCharacters == 0) {
                ans++;
            }
            if (mp.find(txt[i]) != mp.end()) {
                mp[txt[i]]++;
                if (mp[txt[i]] == 1) {
                    countOfDistinctCharacters++;
                }
            }

            // slide the window
            i++;
            j++;
        }
    }
    return ans;
}

int main() {
    string txt = "forxxorfxdofr", pat = "for";
    cout << "Number of occurences of " << pat << " in " << txt <<" is: " << search(pat,txt) << "\n";
}
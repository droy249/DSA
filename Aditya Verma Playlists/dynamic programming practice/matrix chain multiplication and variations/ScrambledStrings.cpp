// Gfg Link: https://www.geeksforgeeks.org/check-if-a-string-is-a-scrambled-form-of-another-string/
// Leetcode Link: https://leetcode.com/problems/scramble-string/
#include <bits/stdc++.h>
using namespace std;

// Video Link: https://youtu.be/VyHEglhbm-A?list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go
unordered_map<string, bool> mp;
bool memoize(string s1, string s2) {
    string key = s1 + " " + s2;

    if (s1.length() != s2.length()) {
        return mp[key] = false;
    }

    if (s1.compare(s2) == 0) {
        return mp[key] = true;
    }

    // if (s1.length() <= 1 || s2.length() <= 1) {
    //     return false;
    // }

    if (mp.find(key) != mp.end()) {
        return mp[key];
    }

    for (auto i = 1; i < s1.length(); i++) {
        // Case 1: Check for substrings that are swapped
        bool condition1 = memoize(s1.substr(0, i), s2.substr(s2.length() - i)) && memoize(s1.substr(i), s2.substr(0, s2.length() - i));

        // Case 2: Check for substrings that not are swapped
        bool condition2 = memoize(s1.substr(0, i), s2.substr(0, i)) && memoize(s1.substr(i), s2.substr(i));

        if (condition1 == true || condition2 == true) {
            return mp[key] = true;
        }
    }

    return mp[key] = false;
}

// Video Link: https://youtu.be/SqA0o-DGmEw?list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go
bool recursive(string s1, string s2) {
    if (s1.length() != s2.length()) {
        return false;
    }

    if (s1.compare(s2) == 0) {
        return true;
    }

    // if (s1.length() <= 1 || s2.length() <= 1) {
    //     return false;
    // }

    for (auto i = 1; i < s1.length(); i++) {
        // Case 1: Check for substrings that are swapped
        bool condition1 = recursive(s1.substr(0, i), s2.substr(s2.length() - i)) && recursive(s1.substr(i), s2.substr(0, s2.length() - i));

        // Case 2: Check for substrings that not are swapped
        bool condition2 = recursive(s1.substr(0, i), s2.substr(0, i)) && recursive(s1.substr(i), s2.substr(i));

        if (condition1 == true || condition2 == true) {
            return true;
        }
    }

    return false;
}

bool isAnagram(const string& s1, const string& s2) {
    int mp[26]{};
    for (auto i = 0; i < s1.length(); i++) {
        ++mp[s1[i] - 'a'];
        --mp[s2[i] - 'a'];
    }
    for (auto i = 0; i < 26; i++) {
        if (mp[i] != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    const string s1("break"), s2("rbkea");
    cout << "\nIs " << s2 << " a scrambled string of " << s1 << "?\n";
    if (s1.empty() || s2.empty() || s1.length() != s2.length() || !isAnagram(s1, s2)) {
        cout << "Not possible to calculate\n";
        return 0;
    }

    cout << "Recursive: " << (recursive(s1, s2) ? "Yes" : "No") << "\n";
    cout << "Memoize: " << (memoize(s1, s2) ? "Yes" : "No") << "\n";
}
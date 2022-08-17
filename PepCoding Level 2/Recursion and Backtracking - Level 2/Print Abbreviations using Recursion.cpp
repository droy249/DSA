// Video Link: https://youtu.be/LliQjLnbhx8?list=PL-Jc9J83PIiHO9SQ6lxGuDsZNt2mkHEn0
// Question Link: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/abbreviation-suing-backtracking-official/ojquestion
// Gfg Link: https://www.geeksforgeeks.org/alphanumeric-abbreviations-of-a-string/
#include <bits/stdc++.h>
using namespace std;

void printAbbreviations(string s, int count = 0, int idx = 0, string ans = "") {
    if (idx == s.size()) {
        if (count > 0)
            cout << ans << count << endl;
        else
            cout << ans << endl;
        return;
    }

    // Include character in ans
    if (count > 0)
        printAbbreviations(s, 0, idx + 1, ans + to_string(count) + s[idx]);
    else
        printAbbreviations(s, 0, idx + 1, ans + s[idx]);

    // Exclude character from ans
    printAbbreviations(s, count + 1, idx + 1, ans);
}

int main() {
    printAbbreviations("qwertyuiop");
}
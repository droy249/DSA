// Question Link: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/max-score-official/ojquestion
// Video Link: https://youtu.be/XtmW3a8Q9M4?list=PL-Jc9J83PIiHO9SQ6lxGuDsZNt2mkHEn0
// Leetcode Link: https://leetcode.com/problems/maximum-score-words-formed-by-letters/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int freq[26] = {};

    int solve(vector<string>& words, vector<int>& score, int i) {
        if (i == words.size()) {
            return 0;
        }

        // Score after excluding words[i]
        int excluded = solve(words, score, i + 1);

        // Score after including words[i]

        // Finding score of words[i] if exists
        int wordScore = 0;
        bool wordScoreExists = true;

        for(auto& letter : words[i]) {
            if(freq[letter - 'a'] == 0) {
                wordScoreExists = false;
            }
            
            --freq[letter - 'a'];
            wordScore += score[letter - 'a'];
        }

        int included = 0;
        if(wordScoreExists) {
            included = wordScore + solve(words, score, i + 1);
        }
        
        for(auto& letter : words[i]) {
            ++freq[letter - 'a'];
        }
        
        return max(included, excluded);
    }

   public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        for (auto& letter : letters) {
            ++freq[letter - 'a'];
        }
        return solve(words, score, 0);
    }
};

int main() {
    vector<string> words = {"dog", "cat", "dad", "good"};
    vector<char> letters = {'a', 'a', 'c', 'd', 'd', 'd', 'g', 'o', 'o'};
    vector<int> score = {1, 0, 9, 5, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    Solution ob;
    cout << "Maximum Score: " << ob.maxScoreWords(words, letters, score);
}
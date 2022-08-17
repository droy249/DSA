// Question Link: 
// Video Link: https://youtu.be/RV0QeTyHZxo?list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp
// Gfg Link: https://www.geeksforgeeks.org/count-number-of-distinct-substring-in-a-string/
#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    Node* links[26];

    // Checks if the reference trie node is present or not
    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    // Creats new reference trie
    void put(char ch) {
        links[ch - 'a'] = new Node();
    }

    // Gets the next node corresponding to given character for traversal
    Node* get(char ch) {
        return links[ch - 'a'];
    }
};

// Time Complexity: O(n * n)
// Space Complexity: O(n) * 26
int countDistinctSubstrings(string& word)  {
    Node* root = new Node();
    int ans = 0;

    for(int i = 0; i < word.size(); ++i) {
        Node* node = root;
        for(int j = i; j < word.size(); ++j) {
            if(!node->containsKey(word[j])) {
                ++ans;
                node->put(word[j]);
            }
            node = node->get(word[i]);
        }
    }

    return ans;
}

// Leetcode Link: https://leetcode.ca/all/1698.html
// Answer Link: https://leetcode.ca/2020-07-24-1698-Number-of-Distinct-Substrings-in-a-String/

int main() {
    string s = "aabbaba";
    cout << "Distinct substrings in " << s << ": " << countDistinctSubstrings(s) << "\n";

    s = "abcdefg";
    cout << "Distinct substrings in " << s << ": " << countDistinctSubstrings(s) << "\n";
}
// Question Link: https://www.codingninjas.com/codestudio/problem-details/complete-string_2687860
// Video Link: https://youtu.be/AWnBa91lThI?list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp
// Leetcode Link: https://leetcode.com/problems/longest-word-in-dictionary/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node *links[26];
    bool endOfWord = false;

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch) {
        links[ch - 'a'] = new Node();
    }

    void setEnd() {
        endOfWord = true;
    }

    bool isEnd() {
        return endOfWord;
    }
};

class Trie {
    Node *root;
public:
    Trie() {
        root = new Node();
    }

    void insert(string& word) {
        Node* node = root;
        for(char& letter : word) {
            if(node->containsKey(letter)) {
                node->put(letter);
            }

            node = node->get(letter);
        }

        node->setEnd();
    }

    bool checkIfPrefixesExist(string& word) {
        bool flag = true;
        Node* node = root;
        
        for(char& letter : word) {
            if(node->containsKey(letter)) {
                node = node->get(letter);
                if(node->isEnd() == false) {
                    return false;
                }
            } else {
                return false;
            }
        }

        return true;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie trie;
        for(string& word: words) {
            trie.insert(word);
        }

        string longest;
        for(string& word : words) {
            if(word.length() > longest.length() && trie.checkIfPrefixesExist(word)) {
                if(word.length() > longest.length()) {
                    longest = word;
                } else if(word.length() == longest.length() && word.compare(longest) < 0) {
                    longest = word;
                }
            }
        }

        return longest;
    }
};
// Video Link: https://youtu.be/dBGUmUQhjaM?list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp
// Question Link: https://www.codingninjas.com/codestudio/problems/implement-trie_631356
#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    Node* links[26];
    bool endOfWord = false;

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

    // After reaching end of word, sets it as true
    void setEnd() {
        endOfWord = true;
    }

    // Check if the end of word has been reached
    bool isEnd() {
        return endOfWord;
    }
};

class Trie {
    Node* root;

   public:
    /* Initializes trie */
    Trie() {
        root = new Node();
    }

    /* Inserts a word into trie */
    /* Time Complexity: O(n), n = length of word */
    void insert(string word) {
        Node* node = root;
        for (char& letter : word) {
            // Check if node for current letter exists
            // If doesn't exist, then create one
            if (!node->containsKey(letter)) {
                node->put(letter);
            }

            // Moves to next node (or Striver says reference node)
            node = node->get(letter);
        }

        node->setEnd();
    }

    /* Searches if word is in the trie */
    /* Time Complexity: O(n), n = length of word */
    bool search(string word) {
        Node* node = root;

        for (char& letter : word) {
            if (!node->containsKey(letter)) {
                return false;
            }

            node = node->get(letter);
        }

        return node->isEnd();
    }

    /* Returns if there is any word in the trie that starts with the given prefix */
    /* Time Complexity: O(n), n = length of prefix */
    bool startsWith(string prefix) {
        Node* node = root;

        for (char& letter : prefix) {
            if (!node->containsKey(letter)) {
                return false;
            }

            node = node->get(letter);
        }

        return true;
    }
};

int main() {
    int n = 5;
    vector<int> type = {1, 1, 2, 3, 2};
    vector<string> value = {"hello", "help", "help", "hel", "hel"};
    Trie trie;

    for (int i = 0; i < n; i++) {
        if (type[i] == 1) {
            trie.insert(value[i]);
        } else if (type[i] == 2) {
            if (trie.search(value[i])) {
                cout << "true" << "\n";
            } else {
                cout << "false" << "\n";
            }
        } else {
            if (trie.startsWith(value[i])) {
                cout << "true" << "\n";
            } else {
                cout << "false" << "\n";
            }
        }
    }
}
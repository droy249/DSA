// Video Link: https://youtu.be/K5pcpkEMCN0?list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp
// Question Link: https://www.codingninjas.com/codestudio/problem-details/implement-trie_1387095
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    Node* links[26];
    int countWords = 0;
    int countPrefixes = 0;

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

    void increaseCountPrefixes(){
        ++countPrefixes;
    }

    void increaseCountWords(){
        ++countWords;
    }

    int getCountWords() {
        return countWords;
    }

    int getCountPrefixes() {
        return countPrefixes;
    }

    void decreaseCountPrefixes() {
        --countPrefixes;
    }

    void decreaseCountWords() {
        --countWords;
    }
};

class Trie {
    Node* root;

public: 
    Trie() {
        root = new Node();
    }

    /* Inserts a word into trie */
    /* Time Complexity: O(n), n = length of word */
    void insert(string word) {
        Node* node = root;
        for(char& letter : word ){
            if(!node->containsKey(letter)) {
                node->put(letter);
            }

            node = node->get(letter);
            node->increaseCountPrefixes();
        }

        node->increaseCountWords();
    }

    /* Returns count of word in the trie */
    /* Time Complexity: O(n), n = length of word */
    int countWordsEqualTo(string& word) {
        Node* node = root;

        for(char& letter : word) {
            if(node->containsKey(letter)) {
                node = node->get(letter);
            } else {
                return 0;
            }
        }
        
        return node->getCountWords();
    }

    /* Returns count of prefixes in the trie */
    /* Time Complexity: O(n), n = length of word */
    int countWordsStartingWith(string& prefix) {
        Node* node = root;
        
        for(char& letter : prefix) {
            if(node->containsKey(letter)) {
                node = node->get(letter);
            } else {
                return 0;
            }
        }

        return node->getCountPrefixes();
    }

    void erase(string& word) {
        Node* node = root;
        
        for(char& letter : word) {
            if(node->containsKey(letter)) {
                node = node->get(letter);
                node->decreaseCountPrefixes();
            } else {
                return;
            }
        }

        node->decreaseCountWords();
    }
};

int main() {
  Trie T;

  T.insert("apple");
  T.insert("apple");
  T.insert("apps");
  T.insert("apps");
  
  string word1 = "apps";
  cout<<"Count Words Equal to "<< word1<<" "<<T.countWordsEqualTo(word1)<<endl;
  
  string word2 = "abc";
  cout<<"Count Words Equal to "<< word2<<" "<<T.countWordsEqualTo(word2)<<endl;
  
  string word3 = "ap";
  cout<<"Count Words Starting With "<<word3<<" "<<T.countWordsStartingWith(word3)<<endl;

  string word4 = "appl";
  cout<<"Count Words Starting With "<< word4<<" "<<T.countWordsStartingWith(word4)<<endl;
  
  T.erase(word1);
  
  cout<<"Count Words equal to "<< word1<<" "<<T.countWordsEqualTo(word1)<<endl;
  
  return 0;
}
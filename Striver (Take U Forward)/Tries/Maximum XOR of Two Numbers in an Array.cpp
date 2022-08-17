// Question Link: https://www.codingninjas.com/codestudio/library/max-xor-of-two-numbers-in-an-array#:~:text=For%20a%20given%20number%20N,log2(N)%20%2B%201.
// Video Link: https://youtu.be/EIhAwfHubE8?list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp
// Explanation Link: https://takeuforward.org/data-structure/maximum-xor-of-two-numbers-in-an-array/
// Leetcode Link: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[2];

    bool containsKey(int bit) {
        return links[bit] != nullptr;
    }

    Node* get(int bit) {
        return links[bit];
    }

    void put(int bit) {
        links[bit] = new Node();
    }
};

class Trie {
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* node = root;
        
        for(int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;

            if(!node->containsKey(bit)) {
                node->put(bit);
            }
            node = node->get(bit);
        }
    }

    int getMax(int num) {
        Node* node = root;
        int maxNum= 0;

        for(int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;

            if(node->containsKey(1 - bit)) {
                maxNum |= 1 << i;
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }

        return maxNum;
    }
};

//

int maxXOR(vector<int>& nums1, vector<int>& nums2) {
    Trie trie;
    for(int& num : nums1) {
        trie.insert(num);
    }

    int res = 0;
    for(int& num : nums2) {
        res = max(res, trie.getMax(num));
    }
}
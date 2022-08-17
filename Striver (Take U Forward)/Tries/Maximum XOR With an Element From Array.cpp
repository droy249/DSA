// Question Link: https://www.codingninjas.com/codestudio/problems/max-xor-queries_1382020?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos
// Video Link: https://youtu.be/Q8LhG9Pi5KM?list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp
// Explanation Link: https://takeuforward.org/data-structure/maximum-xor-of-two-numbers-in-an-array/
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

// Overall Time Complexity: O(N log N + Q log Q + N * 32 + Q * 32)
vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size();
    int q = queries.size();
    
    // Time Complexity: O(N log N)
    sort(nums.begin(), nums.end());
    
    vector<array<int,3>> offlineQueries;
    for(int i = 0; i < q; ++i) {
        offlineQueries.push_back({queries[i][1], queries[i][0], i});
    }

    // Time Complexity: O(Q log Q)
    sort(offlineQueries.begin(), offlineQueries.end(), [](auto& a, auto& b){ return a[0] < b[0]});

    /* Striver Way --> */
    /* Doing this ensures no need to write comparator. Often used in competitive coding */
    /* If this question is asked in an interview, can also use struct */

    // vector<pair<int,pair<int,int>>> offlineQueries;
    // for(int i = 0; i < q; ++i) {
    //     offlineQueries.push_back({queries[i][1], queries[i][0], i});
    // }
    // sort(offlineQueries.begin(), offlineQueries.end());

    Trie trie;
    vector<int> res(q, -1);

    // Time Complexity: O(N * 32) + O(Q * 32)
    for(int i = 0, idx = 0; i < q; ++i) {
        int a = offlineQueries[i][0];
        int x = offlineQueries[i][1];
        int qInd = offlineQueries[i][2];

        while (idx < n && nums[idx] < a){
            trie.insert(nums[idx]);
            idx++;
        }
        
        if(idx > 0) {
            res[qInd] = trie.getMax(x);
        } 
        // else {
        //     res[qInd] = -1;
        // }
    }

    return res;
}

int main() {

}
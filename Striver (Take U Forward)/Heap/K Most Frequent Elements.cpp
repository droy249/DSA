// SDE Sheet Link: https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/#:~:text=K%20most%20frequent%20elements
// Problem Link: https://www.codingninjas.com/codestudio/problems/k-most-frequent-elements_3167808?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
#include <bits/stdc++.h>
using namespace std;

vector<int> KMostFrequent(int n, int k, vector<int> &arr) {
    // Write your code here.
}

// Leetcode Link: https://leetcode.com/problems/top-k-frequent-elements/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(k == nums.size()) return nums;
        
        std::unordered_map<int,int> mp;
        for(const int &num:nums) ++mp[num];

        std::priority_queue<std::pair<int,int>, std::vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        for(const std::pair<int,int> &p:mp){
            minHeap.emplace(p.second, p.first);
            if(minHeap.size() > k)
                minHeap.pop();
        }

        std::vector<int> ans;
        while(!minHeap.empty()){
            ans.emplace_back(minHeap.top().second);
            minHeap.pop();
        }

        return ans;
    }
};
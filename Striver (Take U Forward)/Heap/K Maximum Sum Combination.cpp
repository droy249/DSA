// SDE Sheet Link: https://www.codingninjas.com/codestudio/problems/k-max-sum-combinations_975322?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
// Problem Link: https://www.codingninjas.com/codestudio/problems/k-max-sum-combinations_975322?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
// GFG Link: https://www.geeksforgeeks.org/k-maximum-sum-combinations-two-arrays/
#include <bits/stdc++.h>
using namespace std;

vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k) {
    vector<int> res;
    stable_sort(a.begin(), a.end());
    stable_sort(b.begin(), b.end());

    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({a[n - 1] + b[n - 1], {n - 1, n - 1}});

    set<pair<int, int>> s;
    s.insert({n - 1, n - 1});

    while (res.size() < k) {
        // auto [val, indices] = pq.top();
        // auto [n1, n2] = indices;

        int val = pq.top().first;
        int n1 = pq.top().second.first;
        int n2 = pq.top().second.second;
        pq.pop();

        res.push_back(val);

        pair<int, int> indices = make_pair(n1 - 1, n2);
        if (s.find(indices) == s.end()) {
            pq.push({a[n1 - 1] + b[n2], {n1 - 1, n2}});
            s.insert({n1 - 1, n2});
        }

        indices = make_pair(n1, n2 - 1);
        if (s.find(indices) == s.end()) {
            pq.push({a[n1] + b[n2 - 1], {n1, n2 - 1}});
            s.insert({n1, n2 - 1});
        }
    }

    return res;
}
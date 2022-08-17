// Gfg Link: https://www.geeksforgeeks.org/prims-algorithm-using-priority_queue-stl/
// Explanation Link: https://youtu.be/HnD676J56ak?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// Code Link: https://youtu.be/oNTsS8lGDHw?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

// Time Complexity: O(N + E + N ^ 2)
// Space Complexity: O(N)
void primBrute(int V, vector<pii> adj[], int node = 0) {
    vector<int> key(V, INT_MAX);
    vector<bool> mst(V);
    vector<int> parent(V, -1);

    // Find minimum index not part of mst and having minimum possible key value
    key[node] = 0;

    // Loop iterates for (V-1) no of times for (V-1) edges in final mst
    for(int edge_count = 1; edge_count <= V - 1; ++edge_count) {
        
        // Find minimum key value and its index, which is not part of mst
        int minKeyVal = INT_MAX;
        int minKeyIndex = -1;

        for(int v = 0; v < V; ++v) {
            if(mst[v] == false && key[v] < minKeyVal) {
                minKeyIndex = v;
                minKeyVal = key[v];
            }
        }

        mst[minKeyIndex] = true;

        for (auto [nbr, wt] : adj[minKeyIndex]) {
            if (mst[nbr] == false && wt < key[nbr]) {
                parent[nbr] = minKeyIndex;
                key[nbr] = wt;
            }
        }
    }

    cout << "\nFinal Minimum Spanning Tree (Brute Force Approach): \n";
    for(int v = 0; v < V; ++v) {
        cout << "Parent Node: " << parent[v] << " <----> Child Node: " << v << "\n";
    }
}

// Time Complexity: O(N + E + N log N)
// Space Complexity: O(N)
void primOptimized(int V, vector<pii> adj[], int src = 0) {
    vector<int> key(V, INT_MAX);
    vector<bool> mst(V);
    vector<int> parent(V, -1);


    // Find minimum index not part of mst and having minimum possible key value
    key[src] = 0;
    
    // Initializing priority_queue
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({key[src], src});

    // Loop iterates for (V-1) no of times for (V-1) edges in final mst
    for(int edge_count = 1; edge_count <= V - 1; ++edge_count)  {
        auto [wt, node] = pq.top();
        pq.pop();
        mst[node] = true;

        for(auto& [nbr, nbr_wt] : adj[node]) {
            if (mst[nbr] == false && nbr_wt < key[nbr]) {
                parent[nbr] = node;
                key[nbr] = nbr_wt;
                pq.push({key[nbr], nbr});
            }
        }
    }

    cout << "\nFinal Minimum Spanning Tree (Optimized Approach): \n";
    for(int v = 0; v < V; ++v) {
        cout << "Parent Node: " << parent[v] << " <----> Child Node: " << v << "\n";
    }
}

int main() {
    vector<pii> adj[]{
        {{1, 2}, {3, 6}}, // <- 0
        {{0, 2}, {2, 3}, {3, 8}, {4, 5}}, // <- 1
        {{1, 3}, {4, 7}}, // <- 2
        {{0, 6}, {1, 8}}, // <- 3
        {{1, 5}, {3, 7}} // <- 4
    };

    primBrute(5, adj);
    primOptimized(5, adj);
}
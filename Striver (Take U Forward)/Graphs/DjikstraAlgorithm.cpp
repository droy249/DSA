// Gfg Link: https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
// Complexity: https://takeuforward.org/data-structure/dijkstras-algorithm-shortest-distance/#:~:text=Time%20Complexity%3A,and%20priority%20queue
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

// Video Link: https://youtu.be/jbhuqIASjoM?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// Time Complexity: O((N + E) * log N). Going through N nodes and E edges and log N for priority queue
// Space Complexity: O(N). Distance array and priority queue
void djikstra(int V, vector<pii> adj[], int src = 1) {
    vector<int> distTo(V + 1, numeric_limits<int>::max());
    priority_queue<pii, vector<pii>, greater<pii>> minHeap;
    minHeap.push({distTo[src] = 0, src});

    while (not minHeap.empty()) {
        auto [dist, node] = minHeap.top();
        minHeap.pop();

        for (auto& [next, nextDist] : adj[node]) {
            if (distTo[next] > distTo[node] + nextDist) {
                distTo[next] = distTo[node] + nextDist;
                minHeap.push({distTo[next], next});
            }
        }
    }

    for(int v{1}; v < V; ++v)
        cout << "\nShortest Distance to reach " << v << " from " << src << ": " << distTo[v] << ".\n";
}

struct GFG {
    // Approach 1: Djikstra for adjacency matrix
    // Time Complexity: O(V ^ 2)
    // Space Complexity: O(V ^ 2)
    void dijkstra(vector<vector<int>>& adjMat, int src = 0){
        int V = adjMat.size();
        vector<int> dist(V, INT_MAX);
        vector<bool> sptSet(V);

        for (int i = 0; i < V; ++i){
            
        }
    }
};

int main() {
    // {node, distance}
    vector<pii> adj[] {
        {}, // <- 0
        {{2,2}, {4,1}}, // <- 1
        {{1,2}, {5,5}, {3,4}}, // <- 2
        {{2,4}, {4,3}, {5,1}}, // <- 3
        {{1,1}, {3,3}}, // <- 4
        {{2,5}, {3,1}} // <- 5
    };
    djikstra(6, adj);
}
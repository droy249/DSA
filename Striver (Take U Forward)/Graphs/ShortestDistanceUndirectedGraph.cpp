// Gfg Link: https://www.geeksforgeeks.org/shortest-path-unweighted-graph/
#include <bits/stdc++.h>
using namespace std;

// Video Link: https://youtu.be/hwCWi7-bRfI?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
void shortestDistanceUndirectedGraph(int V, vector<int> adj[], int src = 0) {
    vector<int> distance(V, numeric_limits<int>::max());

    queue<int> q;
    q.emplace(src);
    distance.at(src) = 0;

    while (not q.empty()) {
        int node{q.front()};
        q.pop();

        for (int& nbr : adj[node]) {
            // distance.at(nbr) = max(distance.at(nbr), 1 + distance.at(node));
            // q.emplace(src);
            if (distance.at(node) + 1 < distance.at(nbr)) {
                distance.at(nbr) = distance.at(node) + 1;
                q.emplace(nbr);
            }
        }
    }

    for (int v{}; v < V; ++v)
        cout << "\nDistance of " << src << " from " << v << " is: " << distance.at(v) << ".\n";
}

int main() {
    vector<int> adj[]{{1, 3}, {0, 2, 3}, {1, 6}, {0, 4}, {3, 5}, {4, 6}, {2, 5, 7, 8}, {6, 8}, {6, 7}};
    shortestDistanceUndirectedGraph(9, adj);
}
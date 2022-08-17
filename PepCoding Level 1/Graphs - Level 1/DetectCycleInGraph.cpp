// Question Link: https://nados.io/question/is-graph-cyclic
// Video Link: https://youtu.be/qbQq-k75bcY?list=PL-Jc9J83PIiHfqDcLZMcO9SsUDY4S3a-v
// Gfg Link:
#include <bits/stdc++.h>
using namespace std;

// Striver BFS Approach
// Link: https://youtu.be/A8ko93TyOns?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
class BFS {
    bool checkForCycle(int s, int V, vector<int> adj[], vector<bool>& visited) {
        visited.at(s) = true;
        queue<pair<int, int>> q;
        q.push({s, -1});

        while (not q.empty()) {
            auto [node, parent] = q.front();
            q.pop();

            for (auto& nbr : adj[node])
                if (not visited.at(nbr)) {
                    visited.at(nbr) = true;
                    q.push({nbr, node});
                } else if (parent != nbr)
                    return true;
        }
        return false;
    }

   public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V);

        for (int v = 0; v < V; v++)
            if (not visited.at(v))
                if (checkForCycle(v, V, adj, visited))
                    return true;

        return false;
    }
};

// Striver DFS Approach
// Link: https://youtu.be/Y9NFqI6Pzd4?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
class DFS {
    bool checkForCycle(int node, vector<int> adj[], vector<bool>& visited, int parent = -1) {
        visited.at(node) = true;

        for (auto& nbr : adj[node]) {
            if (not visited.at(nbr)) {
                if (checkForCycle(nbr, adj, visited, node)) {
                    return true;
                }
            } else if (nbr != parent) {
                return true;
            }
        }

        return false;
    }

   public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V);

        for (int v = 0; v < V; v++)
            if (not visited.at(v))
                if (checkForCycle(v, adj, visited))
                    return true;

        return false;
    }
};

// Time Complexity: O(V + E)
// Space Complexity: O(V)
// Analysis: https://nados.io/article/is-graph-cyclic#:~:text=4.-,Analysis,-%3A
vector<bool> visited;
vector<vector<int>> graph;
bool isCyclic(int src) {
    queue<int> q;
    q.push(src);

    while (not q.empty()) {
        int rem{q.front()};
        q.pop();

        if (visited.at(rem))
            return true;

        visited.at(rem) = true;

        for (int& nbr : graph.at(src))
            if (not visited.at(nbr))
                q.push(nbr);
    }

    return false;
}

int main() {
    cout << "\nEnter number of vertices: ";
    int vtces;
    cin >> vtces;

    graph.assign(vtces, {});

    cout << "\nEnter number of edges: ";
    int edges;
    cin >> edges;

    cout << "\nEnter edges:\n";
    for (int i{}; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // write your code here
    visited.assign(vtces, false);
    for (int v{}; v < vtces; v++)
        if (not visited.at(v))
            if (isCyclic(v)) {
                cout << "\nGraph contains a cycle.\n";
                return 0;
            }

    cout << "\nGraph does not contain a cycle.\n";
}
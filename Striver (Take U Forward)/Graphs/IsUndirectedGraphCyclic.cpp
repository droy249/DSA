// GFG Link: https://www.geeksforgeeks.org/detect-cycle-undirected-graph/#:~:text=Depth%20First%20Traversal%20can%20be,the%20tree%20produced%20by%20DFS.
// Practice Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

#include <bits/stdc++.h>
using namespace std;

// BFS Approach
// Video Link: https://youtu.be/A8ko93TyOns?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
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


// DFS Approach
// Video Link: https://youtu.be/Y9NFqI6Pzd4?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
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

        for (int v{}; v < V; v++)
            if (not visited.at(v))
                if (checkForCycle(v, adj, visited))
                    return true;

        return false;
    }
};

// Driver Code
int main() {
    vector<int> graph[]{
        // {1,3},{0,2},{1,3},{0,2}
        {1,2,3},{0,2},{0,1,3},{0,2}
    };

    DFS dfs;
    cout << (dfs.isCycle(4, graph) ? "Cycle exixts." : "Cycle does not exist.") << endl;

    BFS bfs;
    cout << (bfs.isCycle(4, graph) ? "Cycle exixts." : "Cycle does not exist.") << endl;
}
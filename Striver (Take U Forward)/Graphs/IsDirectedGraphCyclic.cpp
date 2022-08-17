// GFG Link: https://www.geeksforgeeks.org/detect-cycle-in-a-graph/
// Practice Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1/

/* During inteviews Striver (link: https://youtu.be/V6GxfKDyLBM?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw) 
recommends to do the DFS solution rather that the BFS solution because it is like a HACK using Kahn's algorithm 
*/
#include <bits/stdc++.h>
using namespace std;

// DFS Approach
// Video Link: https://youtu.be/uzVUw90ZFIg?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
class DFS {
public:
    bool isCyclic (int V, vector<int> adj[]) {
        vector<bool> seen(V), seenInDFS(V);

        for (int v{}; v < V; ++v)
            if (not seen.at(v))
                if (cyclic(v, adj, seen, seenInDFS))
                    return true;
        
        return false;
    }

private:
    bool cyclic(int src, vector<int> adj[], vector<bool>& seen, vector<bool>& seenInDFS) {
        seen.at(src) = seenInDFS.at(src) = true;

        for (int& nbr : adj[src]) {
            if (not seen.at(nbr)) {
                if (cyclic(nbr, adj, seen, seenInDFS)) {
                    return true;
                } 
            } else if (seenInDFS.at(nbr)) {
                return true;
            }
        }

        return seenInDFS.at(src) = false;
    }
};

// BFS Approach (Using Kahn's Algorithm we generate topological sort of given graph. If we are unable to do so, then it has a cycle)
// Video Link: https://youtu.be/V6GxfKDyLBM?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// Leetcode Link: https://leetcode.com/problems/course-schedule/
class BFS {
public:
    bool isCyclic (int V, vector<int> adj[]) {        
        int* inDegree{new int[V]{}};
        for (int v{}; v < V; ++v)
            for (int& nbr : adj[v])
                ++inDegree[nbr];
        
        queue<int> q;
        for (int v{}; v < V; ++v)
            if (inDegree[v] == 0)
                q.emplace(v);

        int topoCount{};
        while (not q.empty()) {
            int node{q.front()};
            q.pop();

            ++topoCount;
            for (int& nbr : adj[node]) 
                if (--inDegree[nbr] == 0)
                    q.emplace(nbr);
        }

        delete[] inDegree;
        return topoCount == V;
    }
};

void addEdge(vector < int > adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Driver Code
int main() {
    int V = 6;

    vector < int > adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 5);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 0);
    addEdge(adj, 4, 1);

    DFS dfs;
    cout << "Graph is " << (dfs.isCyclic(V, adj) ? "" : "not ") << "cyclic.\n";

    BFS bfs;
    cout << "Graph is " << (bfs.isCyclic(V, adj) ? "" : "not ") << "cyclic.\n";
}
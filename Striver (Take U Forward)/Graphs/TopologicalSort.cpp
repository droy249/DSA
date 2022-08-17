/* TOPOLOGICAL SORT OF A GRAPH IS LINEAR ORDERING OF VERTICES SUCH THAT IF THERE IS AN EDGE 'U->V', 'U' APPEARS BEFORE 'V' IN THAT ORDERING.
   IT IS ONLY VALID FOR DIRECTED ACYCLIC GRAPH(DAG)
*/

// Gfg Link: https://www.geeksforgeeks.org/topological-sorting/
// Practice Link: https://practice.geeksforgeeks.org/problems/topological-sort/1/
// Leetcode Question List: https://leetcode.com/tag/topological-sort/
// Leetcode Question Link: https://leetcode.com/problems/course-schedule-ii/
#include <bits/stdc++.h>
using namespace std;

// DFS Approach
// Video Link: https://youtu.be/Yh6EFazXipA?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// Time Complexity: O(V + E)
// Space Complexity: O(V)
class DFS {
public:
    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> sorted;
        bool *visited = new bool[V]{};

        for (int v{}; v < V; ++v) 
            if (not visited[v]) 
                findTopoSort(v, adj, visited, sorted);
        
        delete[] visited;
        return vector<int>(rbegin(sorted), rend(sorted));
    }

private:
    void findTopoSort(int v, vector<int> adj[], bool visited[], vector<int>& sorted) {
        visited[v] = true;

        for(int& nbr : adj[v]) 
            if (not visited[nbr]) 
                findTopoSort(nbr, adj, visited, sorted);

        sorted.emplace_back(v);
    }
};

// BFS Approach (Using Kahn's Algorithm)
// Video Link: https://youtu.be/rZv_jHZva34?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
// Time Complexity: O(V + E)
// Space Complexity: O(V)
class BFS {
public:
    vector<int> topoSort(int V, vector<int> adj[]) {
        // inDegree is the number of edges like in an undirected graph
        vector<int> sorted;
        queue<int> q;
        
        int *inDegree = new int[V]{};
        for (int v{}; v < V; ++v)
            for (int& nbr : adj[v])
                ++inDegree[nbr];

        for (int v{}; v < V; ++v)
            if (inDegree[v] == 0)
                q.emplace(v);

        while (not q.empty()) {
            int node{q.front()};
            q.pop();
            sorted.emplace_back(node);

            for (int& nbr : adj[node]) {
                --inDegree[nbr];

                if (inDegree[nbr] == 0) 
                    q.emplace(nbr);
            }
        }
        

        delete[] inDegree;
        return sorted;
    }
};

// Driver Code
int main() {
    /*
        GRAPH USED: 

        5 -> 0 <- 4
        |         |
        V         V
        2 -> 3 -> 1
    */
    int V = 6;
    vector < int > adj[V];
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    DFS dfs;
    vector <int> fromDFS{dfs.topoSort(V, adj)};

    cout << "\nTopological sort of the given graph is (DFS):\n";
    for (int& node : fromDFS)
        cout << node << " ";
    cout << "\n";

    BFS bfs;
    vector <int> fromBFS{bfs.topoSort(V, adj)};

    cout << "\nTopological sort of the given graph is (BFS):\n";
    for (int& node : fromBFS)
        cout << node << " ";
    cout << "\n";
}
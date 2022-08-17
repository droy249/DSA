// Question Link: https://nados.io/question/breadth-first-traversal
// Video Link: https://youtu.be/GHnC5qHexsk?list=PL-Jc9J83PIiHfqDcLZMcO9SsUDY4S3a-v
#include <bits/stdc++.h>
using namespace std;

// Striver Approach (PREFERRED APPROACH !!!)
// Link: https://youtu.be/UeE67iCK2lQ?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
class Solution {
   public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> bfs;
        bool* visited = new bool[V];

        for (int i = 0; i < V; i++)
            if (not visited[i]) {
                queue<int> q;
                q.push(i);
                visited[i] = true;

                while (not q.empty()) {
                    int node = q.front();
                    q.pop();

                    bfs.push_back(node);
                    for (auto& nbr : adj[node])
                        if (not visited[nbr]) {
                            visited[nbr] = true;
                            q.push(nbr);
                        }
                }
            }
        delete[] visited;
        return bfs;
    }
};

int main() {
    int vtces;
    cin >> vtces;
    vector<int> graph[vtces];

    int edges;
    cin >> edges;

    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int src;
    cin >> src;

    // write your code here

    // pair.first(int) = vertex
    // pair.second(string) = path_so_far
    vector<bool> visited(vtces);
    queue<pair<int, string>> q;
    q.push({src, to_string(src)});

    while (not q.empty()) {
        auto [source, pathSoFar] = q.front();
        q.pop();

        if (visited[source])
            continue;

        visited[source] = true;
        cout << source << "@" << pathSoFar << endl;
        for (int& nbr : graph[source])
            if (not visited[nbr]) {
                pathSoFar.push_back(nbr + '0');
                q.push({nbr, pathSoFar});
                pathSoFar.pop_back();
            }
    }
}

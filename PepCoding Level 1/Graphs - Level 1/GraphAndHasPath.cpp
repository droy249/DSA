// Playlist Link: https://www.youtube.com/playlist?list=PL-Jc9J83PIiHfqDcLZMcO9SsUDY4S3a-v
// Article Link: https://nados.io/content/graphs-for-beginners
// Question Link: https://nados.io/question/has-path
// Video Link: https://youtu.be/mlnnJd9k7oE?list=PL-Jc9J83PIiHfqDcLZMcO9SsUDY4S3a-v
// Leetcode Link: https://leetcode.com/problems/find-if-path-exists-in-graph/
#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(V + E)
// Space Complexity: O(V)
// Link: https://nados.io/article/has-path#:~:text=3.-,Complexities,-%3A
bool hasPath(vector<vector<pair<int, int>>>& edges, int source, int destination, vector<bool>& visited) {
    if (source == destination)
        return true;

    visited[source] = true;

    for (auto& [neighbour, ignore] : edges[source]) {
        if (visited[neighbour] == false) {
            bool neighbourHasPath = hasPath(edges, neighbour, destination, visited);

            if (neighbourHasPath == true)
                return true;
        }
    }

    return false;
}

int main() {
    cout << "\nEnter number of nodes: ";
    int nodes;
    cin >> nodes;

    cout << "\nEnter number of edges: ";
    int edges;
    cin >> edges;

    // ADJACENECY LIST
    // vector<pair<int,int>> adj[nodes + 1];
    vector<vector<pair<int, int>>> adj(nodes + 1, vector<pair<int, int>>());

    /*
        GRAPH BEING CONSTRUCTED:

              10             10
       (0)-----------(3)----------- (4)
        |             |             | \
        |             |             |  \
      10|             |10        10 |   \ 10
        |             |             |    \
        |             |             |     \
       (1)-----------(2)           (5)----(6)
              10                      10
    */

    cout << "\nEnter edges in given format (source, neighbour, weight): \n";
    for (int i{}; i < edges; ++i) {
        int source, neighbour, weight;
        cin >> source >> neighbour >> weight;

        adj[source].push_back({neighbour, weight});
        adj[neighbour].push_back({source, weight});
    }

    cout << "\nEnter path whose existence needs to be confirmed (Enter source followed by destination): ";
    int source, destination;
    cin >> source >> destination;

    vector<bool> visited(nodes);
    cout << "\nPath enquired " << (hasPath(adj, source, destination, visited) ? "" : "does not ") << "exist\n";
}
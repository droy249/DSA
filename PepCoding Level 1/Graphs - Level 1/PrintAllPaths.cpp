// Question Link: https://nados.io/question/print-all-paths
// Video Link: https://youtu.be/DrQ-eTN2v3A?list=PL-Jc9J83PIiHfqDcLZMcO9SsUDY4S3a-v
// Leetcode Link: https://leetcode.com/problems/all-paths-from-source-to-target/
#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(V + E)
// Space Complexity: O(V)
// Analysis: https://nados.io/article/print-all-path#:~:text=4.-,Analysis,-%3A
void printAllPaths(vector<vector<pair<int,int>>>& adj, int source, int destination, vector<bool>& visited, string path = "") {
    if(source == destination){
        cout << path << endl;
        return;
    }

    visited[source] = true;

    for(auto& [neighbour, weight] : adj[source])
        if(visited[neighbour] == false)
            printAllPaths(adj, neighbour, destination, visited, path + to_string(neighbour));
    
    visited[source] = false;
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

    cout << "Enter source: ";
    int source;
    cin >> source;

    cout << "Enter destination: ";
    int destination;
    cin >> destination;

    vector<bool> visited(nodes);
    printAllPaths(adj, source, destination, visited);
}
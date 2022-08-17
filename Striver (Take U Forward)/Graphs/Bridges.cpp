// Gfg Link: https://www.geeksforgeeks.org/bridge-in-a-graph
// Video Link: https://youtu.be/2rjZH0-2lhk?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, bool visited[], vector<int> &timeOfInsertion, vector<int> &lowestTimeOfInsertionWrtAdjacentNodes, int &timer, vector<int> adj[]) {
    visited[node] = true;
    timeOfInsertion[node] = lowestTimeOfInsertionWrtAdjacentNodes[node] = timer++;

    for (const auto& nbr : adj[node]) {
        if (nbr == parent) continue;

        if (!visited[nbr]) {
            dfs(nbr, node, visited, timeOfInsertion, lowestTimeOfInsertionWrtAdjacentNodes, timer, adj);

            lowestTimeOfInsertionWrtAdjacentNodes[node] = min(lowestTimeOfInsertionWrtAdjacentNodes[node], lowestTimeOfInsertionWrtAdjacentNodes[nbr]);
            
            if (lowestTimeOfInsertionWrtAdjacentNodes[nbr] > timeOfInsertion[node]) {
                cout << "Bridge: " << node << " - " << nbr << endl;
            }

        } else {
            lowestTimeOfInsertionWrtAdjacentNodes[node] = min(lowestTimeOfInsertionWrtAdjacentNodes[node], timeOfInsertion[nbr]);
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    vector<int> timeOfInsertion(n, -1);
    vector<int> lowestTimeOfInsertion(n, -1);
    bool visited[n]{};
    
    int timer = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, -1, visited, timeOfInsertion, lowestTimeOfInsertion, timer, adj);
        }
    }

    return 0;
}
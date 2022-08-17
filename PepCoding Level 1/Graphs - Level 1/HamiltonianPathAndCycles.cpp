// Question Link: https://nados.io/question/hamiltonian-path-and-cycle
// Video Link: https://youtu.be/nUgp0RG57wQ?list=PL-Jc9J83PIiHfqDcLZMcO9SsUDY4S3a-v
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int src, nbr, wt;
    Edge(int src, int nbr, int wt) : src(src), nbr(nbr), wt(wt) {}
};

// Time Complexity: O(V + E)
// Space Complexity: O(V)
// Analysis: https://nados.io/article/hamiltonian-path-and-cycle#:~:text=4.-,ANALYSIS,-%3A
void hamiltonian(vector<vector<Edge>>& graph, int src, const int& osrc, unordered_set<int>& visited, vector<int> path = {}) {
    if(graph.size() == visited.size()){
        for(auto& node : path)
            cout << node << " ";
        
        for(Edge& e : graph[src])
            if(e.nbr == osrc) {
                cout << " is a Hamiltonian cycle.\n";
                return;
            }

        cout << " is a Hamiltonian path.\n";
        return;
    }
    
    visited.insert(src);
    path.push_back(src);

    for (Edge& e : graph[src]) 
        if (visited.find(e.nbr) == visited.end())
            hamiltonian(graph, e.nbr, osrc, visited, path);
    
    path.pop_back();
    visited.erase(src);
}

int main() {
    int vtces;
    cin >> vtces;
    vector<vector<Edge>> graph (vtces);

    int edges;
    cin >> edges;
    for (int i = 0; i < edges; i++) {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        graph[v1].push_back(Edge(v1, v2, wt));
        graph[v2].push_back(Edge(v2, v1, wt));
    }

    int src;
    cin >> src;

    unordered_set<int> visited;
    vector<int> path;
    hamiltonian(graph, src, src, visited, path);
}
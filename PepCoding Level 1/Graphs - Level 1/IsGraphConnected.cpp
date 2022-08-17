// Question Link: https://nados.io/question/is-graph-connected
// Video Link: https://youtu.be/dRqO3s14_2s?list=PL-Jc9J83PIiHfqDcLZMcO9SsUDY4S3a-v
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int src, nbr, wt;
    Edge(int src, int nbr, int wt) : src(src), nbr(nbr), wt(wt) {}
};

void drawTreeAndFindComponents(vector<Edge> graph[], int source, vector<int>& component, vector<bool>& visited) {
    visited[source] = true;
    component.emplace_back(source);

    for (Edge& edge : graph[source])
        if (not visited[edge.nbr])
            drawTreeAndFindComponents(graph, edge.nbr, component, visited);
}

int main() {
    int vertices;
    cin >> vertices;
    vector<Edge> graph[vertices];

    int edges;
    cin >> edges;
    for (int i = 0; i < edges; i++) {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        graph[v1].push_back(Edge(v1, v2, wt));
        graph[v2].push_back(Edge(v2, v1, wt));
    }

    int source;
    cin >> source;
    int destination;
    cin >> destination;

    // write your code here
    vector<bool> visited(vertices);
    vector<vector<int>> components;

    for (int v = 0; v < vertices; ++v) {
        if (not visited[v]) {
            vector<int> component;
            drawTreeAndFindComponents(graph, v, component, visited);
            components.emplace_back(component);
        }
    }

    cout << "\nGiven graph " << (components.size() > 1 ? "" : "does not") << " has connected components.\n";
}
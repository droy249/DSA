// Question Link: https://nados.io/question/get-connected-components-of-a-graph
// Video Link: https://youtu.be/8UBwFE8H4Mc?list=PL-Jc9J83PIiHfqDcLZMcO9SsUDY4S3a-v
// Leetcode Link: https://leetcode.com/problems/number-of-provinces/
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int src, nbr, wt;
    Edge(int src, int nbr, int wt) : src(src), nbr(nbr), wt(wt) {}
};

// Time Complexity: O(V)
// Space Complexity: O(h), h = height of recursion stack
// Analysis: https://nados.io/article/get-connected-components-of-a-graph#:~:text=3.-,Analysis,-%3A
void drawTreeAndFindComponents(vector<Edge> graph[], int source, vector<int>& component, vector<bool>& visited) {
    visited[source] = true;
    component.emplace_back(source);

    for (Edge& edge : graph[source])
        if (not visited[edge.nbr])
            drawTreeAndFindComponents(graph, edge.nbr, component, visited);
}

void print(vector<vector<int>>& components) {
    cout << "[";
    for (int i = 0; i < components.size(); i++) {
        cout << "[";
        for (int j = 0; j < components[i].size(); j++) {
            cout << components[i][j];
            if (j != components[i].size() - 1)
                cout << ", ";
        }
        cout << "]";
        if (i != components.size() - 1) cout << ", ";
    }
    cout << "]";
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

    vector<vector<int>> components;

    // write your code here
    vector<bool> visited(vertices);
    for (int v = 0; v < vertices; ++v) {
        if (not visited[v]) {
            vector<int> component;
            drawTreeAndFindComponents(graph, v, component, visited);
            components.emplace_back(component);
        }
    }

    print(components);
}
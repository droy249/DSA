// Question Link: https://nados.io/question/perfect-friends
// Video Link: https://youtu.be/_q4hA01ZcVQ?list=PL-Jc9J83PIiHfqDcLZMcO9SsUDY4S3a-v
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int vertex, neighbour;
    Edge(int vertex, int neighbour) : vertex(vertex), neighbour(neighbour) {}
};

// Time Complexity: O(V + E)
// Space Complexity: O(V)
// Analysis: https://nados.io/article/perfect-friends#:~:text=4.-,Analysis,-%3A
void drawTreeAndFindComponents(vector<Edge> graph[], int src, vector<int>& component, vector<bool>& visited) {
    visited[src] = true;
    component.push_back(src);

    for(Edge& e : graph[src]) 
        if(not visited[e.neighbour]) {
            drawTreeAndFindComponents(graph, e.neighbour, component, visited);
        }
}

int main() {
    cout << "\nEnter number of friends: ";
    int friends;
    cin >> friends;

    cout << "\nEnter number of groups: ";
    int groups;
    cin >> groups;

    vector<Edge> graph[friends];
    cout << "\nEnter friends groups:\n";
    for (int i = 0; i < groups; ++i) {
        int friend1, friend2;
        cin >> friend1 >> friend2;

        graph[friend1].push_back(Edge(friend1, friend2));
        graph[friend2].push_back(Edge(friend2, friend1));
    }

    vector<bool> visited(friends, false);
    vector<vector<int>> components;

    for (int f = 0; f < friends; ++f) {
        if (not visited[f]) {
            vector<int> component;
            drawTreeAndFindComponents(graph, f, component, visited);
            components.push_back(component);
        }
    }

    int pairs = 0;
    for (int i = 0; i < components.size(); ++i) {
        for (int j = i + 1; j < components.size(); ++j) {
            pairs += components[i].size() * components[j].size();
        }
    }

    cout << "\nNumber of required pairs: " << pairs << endl;
}
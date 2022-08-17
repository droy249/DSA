// Gfg Link:
// Video Link: 
#include <bits/stdc++.h>
using namespace std;

void disjointSet(int V, vector<int> adj[] = {}) {
    int parent[V], rank[V]{};

    // Initially set every node as its own parent
    for (int v = 0; v < V; ++v) {
        parent[v] = v;
    }

    for(int v = 0; v < V; ++v){
        cout << v << " -> " << parent[v] << " " << rank[v] << "\n";
    }
    // delete[] rank;
}



int main (){
    disjointSet(6);
}
// Gfg Link: https://www.geeksforgeeks.org/shortest-path-for-directed-acyclic-graphs/
// Intuition behind using topological sort: https://stackoverflow.com/questions/37253739/intuition-behind-the-algorithm-to-compute-single-source-shortest-path-for-every
#include <bits/stdc++.h>
using namespace std;

void findTopoSort(int src, vector<pair<int,int>> adj[], bool visited[], stack<int>& topoSorted) {
	visited[src] = true;
	
	for (auto& [nbr,wt] : adj[src])
		if (not visited[nbr])
			findTopoSort(nbr, adj, visited, topoSorted);
	
	topoSorted.emplace(src);
}

stack<int> topologicalSort(int V, vector<pair<int,int>> adj[]) {
	// bool* visited{new bool[V]{}};
	bool visited[V]{false};
	stack<int> topoSorted;
	
	for(int v{}; v < V; ++v)
		if(not visited[v])
			findTopoSort(v, adj, visited, topoSorted);
	
	// delete[] visited;
	return topoSorted;
}

// Video Link: https://youtu.be/CrxG4WJotgg?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
void shortestDistanceDAG(int V, vector<pair<int, int>> adj[], int src = 0) {
    vector<int> distance(V, numeric_limits<int>::max());
	distance.at(src) = 0;
    
	stack<int> st{topologicalSort(V, adj)};
	while (not st.empty()) {
		int node{st.top()};
		st.pop();
		
		// If the node has been reached previously
		if(distance.at(node) != numeric_limits<int>::max())
			for(auto& [nbr,wt] : adj[node])
				distance.at(nbr) = min(distance.at(nbr), distance.at(node) + wt);
	}
	
	for(int v{}; v < V; ++v)
		cout << "\nDistance of " << v << " from " << src << ": " << (distance.at(v) == numeric_limits<int>::max() ? "INFINITY" : to_string(distance.at(v))) << ".\n";
}

int main() {
	int V{6};
	vector<pair<int,int>> adj[6]{
        {{1, 2}, {4, 1}}, // <- 0
        {{2, 3}}, // <- 1
        {{3, 6}}, // <- 2
        {}, // <- 3
        {{2, 2}, {5, 4}}, // <- 4
        {{3, 1}} // <- 5
    };
    shortestDistanceDAG(V, adj);
}
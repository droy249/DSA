// Gfg Link: https://www.geeksforgeeks.org/bipartite-graph/
// Practice Link: https://practice.geeksforgeeks.org/problems/bipartite-graph/1/
// Leetcode Link: https://leetcode.com/problems/is-graph-bipartite/
#include <bits/stdc++.h>
using namespace std;

// BFS Approach Link: https://youtu.be/nbgaEu-pvkU?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
class BFS {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> color(V);
        
        for (int v{}; v < V; ++v)
            if (not color.at(v))
                if(not bipartiteChecker(v, color, adj))
                    return false;
        
        return true;
	}
    
private:
    bool bipartiteChecker(int src, vector<int>& color, vector<int> adj[]) {
        queue<int> q;
        q.emplace(src);
        color.at(src) = 1;
        
        while (not q.empty()) {
            int node{q.front()};
            q.pop();
            
            for (int& nbr : adj[node]) 
                if (not color.at(nbr)) {
                    color.at(nbr) = -color.at(node);
                    q.emplace(nbr);
                } else if (color.at(nbr) == color.at(node))
                    return false;
            
        }
        return true;
    }
};

// DFS Approach Link: https://youtu.be/uC884ske2uQ?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
class DFS {
public:
    bool isBipartite(int V, vector<int>adj[]) {
        // Code here
	    vector<int> color(V);
        
        for (int v{}; v < V; ++v)
            if (not color.at(v)) 
                if(not bipartiteChecker(v, color, adj))
                    return false;
        
        return true;
    }

private:
    bool bipartiteChecker(int src, vector<int>& color, vector<int>adj[]) {
        if (not color.at(src))
            color.at(src) = 1;

        for(int& nbr : adj[src])
            if (not color.at(nbr)) {
                color.at(nbr) = -color.at(src);
                if (not bipartiteChecker(nbr, color, adj))
                    return false;
            } else if (color.at(nbr) == color.at(src))
                return false;

    return true;
    }
};

// Driver Code
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> adj[n];
	for(int i = 0;i<m;i++) {
	    int u, v;
	    cin >> u >> v;
	    adj[u].push_back(v); 
	    adj[v].push_back(u); 
	}
	
	BFS bfs;
    cout << "Graph is " << (bfs.isBipartite(n, adj) ? "" : "not ") << "bipartite.\n";

    DFS dfs;
    cout << "Graph is " << (dfs.isBipartite(n, adj) ? "" : "not ") << "bipartite.\n";
}

/*
8 7 
0 1 
1 2 
2 3 
3 4 
4 6 
6 7 
1 7
4 5 

// bipartite graph example 
*/ 

/*
7 7 
0 1 
1 2 
2 3 
3 4 
4 6 
6 1
4 5 
// not bipartite example
*/
// Question Link: https://nados.io/question/multisolver-smallest-longest-ceil-floor-kthlargest-path
// Video Link: https://youtu.be/PSy0yJQx050?list=PL-Jc9J83PIiHfqDcLZMcO9SsUDY4S3a-v
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int src, nbr, wt;
    Edge(int src, int nbr, int wt) : src(src), nbr(nbr), wt(wt) {}
};

struct myComp {
    bool operator()( pair<int, string>& a, pair<int, string>& b) {
        return a.first > b.first;
    }
};

string spath;               // spath = smallest path
int spathwt = INT_MAX;      // spathwt = smallest path weight
string lpath;               // lpath = largest path
int lpathwt = INT_MIN;      // lpathwt = largest path weight
string cpath;               // cpath = ceil path
int cpathwt = INT_MAX;      // cpath ceil path weight
string fpath;               // fpath = floor path
int fpathwt = INT_MIN;      // fpathwt =  = floor path weight
int criteria;
int k;
vector<bool> visited;

priority_queue<pair<int, string>, vector<pair<int, string>>, myComp> pq;

/* psf = path so far
   wsf = weight so far 
 */
// Time Complexity: O(V + E)
// Space Complexity: O(V)
// Analysis: https://nados.io/article/multisolver-smallest-longest-ceil-floor-kth-largest-path#:~:text=4.-,ANALYSIS,-%3A
void multisolver(vector<Edge> graph[], int src, int dest, string psf, int wsf) {
    if (src == dest) {
        if (wsf < spathwt ) {
            spathwt = wsf;
            spath = psf;
        }

        if (wsf > lpathwt) {
            lpathwt = wsf;
            lpath = psf;
        }

        if (wsf > criteria and wsf < cpathwt) {
            cpathwt = wsf;
            cpath = psf;
        }

        if (wsf < criteria and wsf > fpathwt) {
            fpathwt = wsf;
            fpath = psf;
        }

        pq.emplace(wsf, psf);
        if (pq.size() > k) {
            pq.pop();
        }

        return;
    }

    visited[src] = true;
    for(Edge& edge : graph[src]) {
        if(not visited[edge.nbr]) {
            multisolver(graph, edge.nbr, dest, psf + to_string(edge.nbr), wsf + edge.wt);
        }
    }
    visited[src] = false;
}

int main() {
    int vtces;
    cin >> vtces;
    vector<Edge> graph[vtces];

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
    int dest;
    cin >> dest;

    cin >> criteria;
    cin >> k;

    visited.assign(vtces, false);
    multisolver(graph, src, dest, src + "0", 0);

    cout << "Smallest Path = " << spath << "@" << spathwt << endl;
    cout << "Largest Path = " << lpath << "@" << lpathwt << endl;
    cout << "Just Larger Path than " << criteria << " = " << cpath << "@" << cpathwt << endl;
    cout << "Just Smaller Path than " << criteria << " = " << fpath << "@" << fpathwt << endl;
    auto [weight, path] = pq.top();
    cout << k << "th largest path = " << path << "@" << weight << endl;
}
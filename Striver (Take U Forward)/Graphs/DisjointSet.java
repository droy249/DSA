// Video Link: https://youtu.be/3gbO7FDYNFQ?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw

public class DisjointSet {
    static int[] parent, rank;

    private static void makeSet() {
        for (int i = 0; i < rank.length; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    private static int findParent(int node) { 
        if (node == parent[node]) {
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }

    private static void union(int u, int v) {
        u = findParent(u);
        v = findParent(v);

        if (rank[u] < rank[v]) {
            parent[u] = v;
        } else if (rank[u] > rank[v]) {
            parent[v] = u;
        } else {
            parent[v] = u;
            ++rank[u];
        }
    }

    public static void main(String[] args) {
        int n = 8;
        parent = new int[n];
        rank = new int[n];
        makeSet();

        union(1, 2);
        union(2, 3);
        union(4, 5);
        union(6, 7);
        union(5, 6);
        union(3, 7);

        System.out.println("Parent of 2 and 3 are same? " + (findParent(2) == findParent(3)));
    }
}
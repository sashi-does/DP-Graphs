class DSU {
    vector<int> parent;
    DSU(int edges) {
        parent.resize(edges, 0);
        for(int i = 0;  i < edges; i++)
            parent[i] = i;
    }
    // o(n^2) worst not optimised
    int find(int n) {
        if(n == parent[n])
            return n;
        return find(parent[n]);
    }
    void merge_union(int a, int b) {
        int x_parent = find(a);
        int y_parent = find(b);
        if(x_parent != y_parent)
            parent[x_parent] = y_parent;
    }
};
class DSU {
    vector<int> rank;
    vector<int> parent;
    int edges;
    DSU(int edges) {
        this->edges = edges;
        rank.resize(edges, 0);
        parent.resize(edges, 0);
        for(int i = 0; i < edges; i++)
            parent[i] = i;
    }

    int find(int node) {
        if(parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }

    void merge_union(int a, int b) {
        int a_parent = find(a);
        int b_parent = find(b);
        if(a_parent == b_parent)
            return;

        if(rank[a_parent] < rank[b_parent]) {
            parent[a_parent] = b_parent;
        }
        else if(rank[a_parent] > rank[b_parent]) {
            parent[b_parent] = a_parent;
        }
        else {
            parent[b_parent] = a_parent;
            rank[a_parent]++;
        }
    }

};
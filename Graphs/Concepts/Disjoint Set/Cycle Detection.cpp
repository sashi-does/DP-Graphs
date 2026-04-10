class Solution {
  public:
    vector<int> rank;
    vector<int> parent;
    bool hasCycle = false;
    int find(int node) {
        if(parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }
    void union_merge(int a, int b) {
        int parent_a = find(a);
        int parent_b = find(b);
        if(parent_a == parent_b)
            return;
        if(rank[parent_a] < rank[parent_b]) 
            parent[parent_a] = parent_b;
        else if(rank[parent_a] > rank[parent_b])
            parent[parent_b] = parent_a;
        else {
            parent[parent_a] = parent_b;
            rank[parent_b]++;
        }
    }
    int detectCycle(int V, vector<int> adj[]) {
        rank.resize(V, 0);
        parent.resize(V, 0);
        for(int i = 0; i < V; i++) 
            parent[i] = i;
        for(int u = 0; u < V; u++) {
            for(int v : adj[u]) {
                if(u < v) {
                    int par_u = find(u);
                    int par_v = find(v);
                    if(par_u == par_v)
                        return true;
                    union_merge(u, v);
                }
            }
        }
        return hasCycle;
        
    }
};
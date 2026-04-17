// https://www.geeksforgeeks.org/problems/minimum-spanning-tree-kruskals-algorithm/1

class DSU {
public:
    vector<int> parent;
    vector<int> rank;
    DSU(int v) {
        parent.resize(v, 0);
        for(int i = 0; i < v; i++)
            parent[i] = i;
        rank.resize(v, 0);
    }
    int find(int node) {
        if(node == parent[node])
            return node;
        return parent[node] = find(parent[node]);
    }
    void Union(int u, int v) {
        int parentU = find(u), parentV = find(v);
        if(rank[parentU] < rank[parentV]) {
            parent[parentU] = parentV;
        }
        else if(rank[parentU] > rank[parentV]) {
            parent[parentV] = parentU;
        }
        else {
            parent[parentV] = parentU;
            rank[parentU]++;
        }
    }
    
};

class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        DSU dsu(V);
        int sum = 0;
        sort(edges.begin(), edges.end(), [&](const vector<int> &a, const vector<int>& b) {
            return a[2] < b[2];
        });
        for(auto &edge : edges) {
            int u = edge[0], v = edge[1], wt = edge[2];
            int parentV = dsu.find(u);
            int parentU = dsu.find(v);
            if(parentU != parentV) {
                dsu.Union(u, v);
                sum += wt;
            }
        }
        return sum;
        
    }
};
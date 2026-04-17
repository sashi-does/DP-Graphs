// https://leetcode.com/problems/min-cost-to-connect-all-points/description/

class DSU {
public:
    vector<int> parent;
    vector<int> rank;
    DSU(int v) {
        parent.resize(v);
        for(int i = 0; i < v; i++)
            parent[i] = i;
        rank.resize(v, 0);
    }
    int find(int node) {
        if(parent[node] == node) 
            return node;
        return parent[node] = find(parent[node]);
    }
    void Union(int u, int v) {
        int parentU = find(u);
        int parentV = find(v);
        if(rank[parentU] < rank[parentV]) {
            parent[parentU] = parent[parentV];
        }
        else if(rank[parentU] > rank[parentV]) {
            parent[parentV] = parent[parentU];
        }
        else {
            parent[parentU] = parentV;
            rank[parentU]++;
        }
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<tuple<int, int, int>> edges(n);
        for(int i = 0; i < points.size(); i++) {
            for(int j = i + 1; j < points.size(); j++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                edges.push_back({abs(x1 - x2) + abs(y1 - y2), i, j});
            }
        }
        DSU dsu(n);
        int sum = 0;
        sort(edges.begin(), edges.end());
        for(int i = 0; i < edges.size(); i++) {
            auto [wt, u, v] = edges[i];
            int parentU = dsu.find(u);
            int parentV = dsu.find(v);
            if(parentU != parentV) {
                dsu.Union(parentU, parentV);
                sum += wt;
            }
        }
        return sum;
    }
};

    
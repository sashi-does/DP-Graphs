// https://leetcode.com/problems/number-of-operations-to-make-network-connected/

class DSU {
public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n) {
        parent.resize(n, 0);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int i) {
        if(parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    void Union(int a, int b) {
        int a_parent = find(a);
        int b_parent = find(b);
        if(rank[a_parent] < rank[b_parent]) {
            parent[a_parent] = b_parent;
        }
        else if(rank[a_parent] > rank[b_parent]) {
            parent[b_parent] = a_parent;
        }
        else {
            parent[a_parent] = b_parent;
            rank[b_parent]++;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1)
            return -1;
        DSU dsu(n);
        for(auto &conn : connections) {
            if(conn[0] < conn[1])
                dsu.Union(conn[0], conn[1]);
        }
        unordered_set<int> parents;
        for(auto &parent: dsu.parent)
            parents.insert(dsu.find(parent));
        return parents.size() - 1;
    }
};
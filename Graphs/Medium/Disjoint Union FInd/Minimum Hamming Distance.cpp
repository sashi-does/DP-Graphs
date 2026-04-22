// https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/description/

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
        if(parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }
    void Union(int a, int b) {
        int par_a = this->find(a);
        int par_b = this->find(b);
        if(rank[par_a] < rank[par_b]) {
            parent[par_a] = par_b;
        }
        else if(rank[par_a] > rank[par_b]) {
            parent[par_b] = par_a;
        }
        else {  
            parent[par_a] = par_b;
            rank[par_b]++;
        }
    }
};

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        unordered_map<int, unordered_map<int, int>> store;
        int v = source.size();
        DSU dsu(v);
        for(auto &swap : allowedSwaps) {
            dsu.Union(swap[0], swap[1]);
        }
        for(int i = 0; i < v; i++) {
            int parent = dsu.find(i);
            store[parent][source[i]]++;
        }
        int hamDist = 0;
        for(int i = 0; i < v; i++) {
            int parent = dsu.find(i);
            if(store[parent][target[i]] > 0) 
                store[parent][target[i]]--;
            else 
                hamDist++;

        }
        return hamDist;
    }
};
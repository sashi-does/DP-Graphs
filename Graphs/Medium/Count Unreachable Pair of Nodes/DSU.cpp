// https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/

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
        int parent_a = find(a);
        int parent_b = find(b);
        if(parent_a != parent_b) {
            if(rank[parent_a] < rank[parent_b]) {
                parent[parent_a] = parent_b;
            }
            else if(rank[parent_a] > rank[parent_b]) {
                parent[parent_b] = parent_a;
            }   
            else {
                parent[parent_a] = parent_b;
                rank[parent_b]++;
            }
        }
    }
};

class Solution {
public:
    vector<int> sum;
    long long countPairs(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for(auto &edge : edges) {
            dsu.Union(edge[0], edge[1]);
        }
        unordered_map<int, int> store;
        for(int i =0; i < n; i++) {
            store[dsu.find(i)]++;
        }
        vector<int> sum;
        for(auto &it : store)
            sum.push_back(it.second);
        long long res = 0;
        long long tot = accumulate(sum.begin(), sum.end(), 0LL);
        for(int i = 0; i < sum.size(); i++) {
            tot -= sum[i];
            res += (sum[i] * tot);
        }
        return res;
    }
};
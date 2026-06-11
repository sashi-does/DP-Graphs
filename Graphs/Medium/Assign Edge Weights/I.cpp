// https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-i

class Solution {
public:
    const int MOD = 1e9 + 7;
    int dfs(int node, int parent, vector<vector<int>>& adj) {
        // int depth = 0;
        int depth = -1;
        for(int neigh : adj[node]){
            if(neigh != parent) {
                // depth = max(depth, 1 + dfs(neigh, node, adj));
                depth = max(depth, dfs(neigh, node, adj));
            }
        }
        // return depth;
        return depth + 1;
    }

    long long pow(int a, int b) {
        if(b <= 0)
            return 1;
        long long div = pow(a, b / 2);
        long long whole = (div * div) % MOD;

        if(b % 2 == 1) {
            whole = (whole * a) % MOD;
        }
        return whole % MOD;

    }

    int assignEdgeWeights(vector<vector<int>>& edges) {

        int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);
        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        int maxDepth = dfs(1, -1, adj);
        // int res = int(pow(2, maxDepth - 1)) % MOD;

        int res = pow(2, maxDepth - 1);
        
        return res;
    }
};
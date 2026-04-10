// https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/

class Solution {
public:
    vector<int> sum;
    vector<bool> visited;
    int DFS(int node, vector<vector<int>>& adj) {
        visited[node] = true;
        int total = 0;
        for(int num : adj[node]) {
            if(!visited[num])
                total += 1 + DFS(num, adj);
        }
        return total;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        visited.resize(n, false);
        vector<vector<int>> adj(n);
        for(auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);

        }
        for(int i = 0; i < n; i++) {
            if(!visited[i])
                sum.push_back(DFS(i, adj) + 1); 
        }
        long long res = 0;
        long long tot = accumulate(sum.begin(), sum.end(), 0LL);
        for(int i = 0; i < sum.size(); i++) {
            tot -= sum[i];
            res += (sum[i] * tot);
        }
        return res;
    }
};
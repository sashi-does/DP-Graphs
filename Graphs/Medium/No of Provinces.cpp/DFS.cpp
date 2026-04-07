// https://leetcode.com/problems/number-of-provinces/description/

class Solution {
public:
    vector<bool> visited;
    void dfs(vector<vector<int>>& adj, int node, int parent) {
        visited[node] = true;
        for(auto &n : adj[node]) {
            if(parent == n)
                continue;
            if(visited[n])
                continue;
            dfs(adj, n, node);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<vector<int>> adj(v);
        visited = vector<bool>(v, false);
        for(int i = 0; i < v; i++) {
            for(int j = 0; j < v; j++) {
                if(i != j && isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                }
            }
        }
        int provinces = 0;
        for(int i = 0; i < v; i++) {
            if(!visited[i]) {
                provinces++;
                dfs(adj, i, -1);
            }
        }
        return provinces;
    }
};
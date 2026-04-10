// https://leetcode.com/problems/number-of-operations-to-make-network-connected/

class Solution {
public:
    vector<bool> visited;
    int enclaves = 0;
    void DFS(int node, vector<vector<int>>& adj) {
        visited[node] = true;
        for(int n : adj[node]) {
            if(!visited[n]) {
                DFS(n, adj);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1) 
            return -1;
        vector<vector<int>> adj(n);
        for(int i = 0; i < connections.size(); i++) {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        visited.resize(n, false);
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                DFS(i, adj);
                enclaves++;
            }
        }
        return enclaves - 1;
    }
};
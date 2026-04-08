// https://leetcode.com/problems/number-of-provinces/description/

class Solution {
public:
    vector<bool> visited;
    void dfs(vector<vector<int>>& adj, int node) {
        visited[node] = true;
        for(int i = 0; i < adj.size(); i++) {
            if(visited[i] || !adj[node][i])
                continue;
            dfs(adj, i);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        visited = vector<bool>(v, false);
        // vector<vector<int>> adj(v);
        // for(int i = 0; i < v; i++) {
        //     for(int j = 0; j < v; j++) {
        //         if(i != j && isConnected[i][j] == 1) {
        //             adj[i].push_back(j);
        //         }
        //     }
        // }
        int provinces = 0;
        for(int i = 0; i < v; i++) {
            if(!visited[i]) {
                provinces++;
                dfs(isConnected, i);
            }
        }
        return provinces;
    }
};
// https://leetcode.com/problems/number-of-provinces/description/

class Solution {
public:
    vector<bool> visited;
    int count;
    void BFS(vector<vector<int>>& adj, int node) {
        queue<int> q;
        q.push(node);
        visited[node] = true;
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            for(int i = 0; i < adj.size(); i++) {
                if(!visited[i] && adj[front][i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        // vector<vector<int>> adj(n);
        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < n; j++) {
        //         if(i != j && isConnected[i][j])
        //             adj[i].push_back(j);
        //     }
        // }
        visited = vector<bool>(n, false);
        count = 0;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                BFS(isConnected, i);
                count++;
            }
        }
        return count;

    }
};
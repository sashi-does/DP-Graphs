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
            for(auto &n : adj[front]) {
                if(!visited[n]) {
                    visited[n] = true;
                    q.push(n);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j && isConnected[i][j])
                    adj[i].push_back(j);
            }
        }
        visited = vector<bool>(n, false);
        count = 0;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                BFS(adj, i);
                count++;
            }
        }
        return count;

    }
};
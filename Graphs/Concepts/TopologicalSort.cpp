class Solution {
  public:
    vector<int> temp;
    void findOrderDFS(
        vector<bool>& visited, 
        vector<vector<int>>& adj, int node, stack<int>& stk
    ) {
        visited[node] = true;
        for(auto &n : adj[node]) {
            if(visited[n])
                continue;
            findOrderDFS(visited, adj, n, stk);
        }
        stk.push(node);
        return;
        
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        stack<int> stk;
        for(int i = 0; i < edges.size(); i++) 
            adj[edges[i][0]].push_back(edges[i][1]);
        vector<bool> visited(V, false);
        for(int i = 0; i < V; i++) {
            if(!visited[i])findOrderDFS(visited, adj, i, stk);
        }
        vector<int> temp;
        while(!stk.empty()) {
            temp.push_back(stk.top());
            stk.pop();
        }
        return temp;
    }
};
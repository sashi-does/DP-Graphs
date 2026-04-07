class Solution {
  public:
    // ############### Using DFS ###############
    bool hasCycleDFS(
        vector<vector<int>>& adj, 
        vector<bool>& visited, int node, int parent
    ) {
        visited[node] = true;
        for(auto &n : adj[node]) {
            if(parent == n)
                continue;
            if(visited[n])
                return true;
            if(hasCycleDFS(adj, visited, n, node))
                return true;
        }
        return false;
    }

    // ############### Using BFS ###############
    bool hasCycleBFS(
        vector<vector<int>>& adj, 
        vector<bool>& visited, int node, int parent
    ) {
        queue<pair<int, int>> q;
        q.push({node, parent});
        visited[node] = true;
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                auto front = q.front();
                q.pop();
                int currChild = front.first, currParent = front.second;
                for(auto &n : adj[currChild]) {
                    if(currParent == n)
                        continue;
                    if(visited[n])
                        return true;
                    visited[n] = true;
                    q.push({n, currChild});
                }
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<bool> visited(V, false);
        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i = 0; i < V; i++) {
            if(!visited[i] && hasCycleBFS(adj, visited, i, -1)) {
                return true;
            }
        }
        return false;
        
    }
};
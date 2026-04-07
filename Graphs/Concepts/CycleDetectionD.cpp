// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

// ############### Using DFS ###############
bool hasCycleDFS(
    vector<vector<int>>& adj, 
    int node, vector<bool>& visited
) {
    visited[node] = true;
    for(auto &n : adj[node]) {
        if(visited[n])
            return true;
        if(hasCycleDFS(adj, n, visited)) {
            return true;
        }
        visited[n] = false;
    }
    return false;
}

// ############### Using BFS ###############
bool hasCycleBFS(
    vector<vector<int>>& adj, 
    int node, vector<bool>& visited
) {
    queue<int> q;
    q.push(node);
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        for(auto &n : adj[front]) {
            if(visited[n])
                return true;
            q.push(n);
            visited[n] = true;
        }
    }
    return false;
}

bool isCyclic(int V, vector<vector<int>> &edges) {
    vector<vector<int>> adj(V);
    for(int i = 0; i < edges.size(); i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    
    for(int i = 0; i < V; i++) {
        vector<bool> visited(V, false);
        if (hasCycleDFS(adj, i, visited)) {
            return true;
        }
    }
    return false;
    
}
// https://www.geeksforgeeks.org/problems/diameter-of-a-graph/1

class Solution {
  public:
    pair<int, int> BFS(int V, vector<vector<int>>& edges, int src) {
        int level = -1, farthestNode = src;
        queue<int> q;
        vector<bool> visited(V, false);
        q.push(src);
        visited[src] = true;
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                int front = q.front();
                farthestNode = front;
                q.pop();
                for(int node : edges[front]) {
                    if(!visited[node]) {
                        visited[node] = true;
                        q.push(node);
                    }
                }
            }
            level++;
        }
        return {farthestNode, level};
        
    }
    int diameter(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        auto [node, dist] = BFS(V, adj, 0);
        return BFS(V, adj, node).second;
    }
};

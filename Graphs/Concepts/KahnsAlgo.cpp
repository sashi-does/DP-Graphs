class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> inDegree(V, 0);
        vector<vector<int>> adj(V);
        for(int i = 0; i < edges.size(); i++) 
            adj[edges[i][0]].push_back(edges[i][1]);
            
        for(int i = 0; i < V; i++) {
            for(int node : adj[i])
                inDegree[node]++;
        }
        
        queue<int> q;
        for(int i = 0; i < V; i++) {
            if(inDegree[i] == 0) 
                q.push(i);
        }
        vector<int> temp;
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                int front = q.front();
                temp.push_back(front);
                q.pop();
                for(int node : adj[front]) {
                    inDegree[node]--;
                    if(inDegree[node] == 0)
                        q.push(node);
                }
            }
        }
        return temp;
    }
};
// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

typedef tuple<int, int> T;
class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(V);
        for(auto &edge : edges) {
            adj[edge[1]].push_back({edge[0], edge[2]});
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
        priority_queue<T, vector<T>, greater<T>> pq;
        vector<bool> visited(V, false);
        
        int sum = 0;
        pq.push({0, 0});
        while(!pq.empty()) {
            auto [wt, node] = pq.top();
            pq.pop();
            
            if(visited[node])
                continue;
                
            visited[node] = true;
            sum += wt;
            
            for(auto p : adj[node]) {
                auto [curr_neigh, curr_wt] = p;
                if(visited[curr_neigh] == false) {
                    
                    pq.push({curr_wt, curr_neigh});
                }
            }
        }
        return sum;
        
    }
};
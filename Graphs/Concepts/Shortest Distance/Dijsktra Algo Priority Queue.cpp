// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>> adj(V);
        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> res(V, INT_MAX);
        res[src] = 0;
        pq.push({0, src});
        while(!pq.empty()) {
            pair<int, int> front = pq.top();
            pq.pop();
            int dist = front.first;
            int node = front.second;
            if(res[node] < dist)
                continue;
            for(auto &p : adj[node]) {
                if(res[p.first] > dist + p.second) {
                    res[p.first] = dist + p.second;
                    pq.push({res[p.first], p.first});
                }
            }
        }
        
        return res;
        
    }
};
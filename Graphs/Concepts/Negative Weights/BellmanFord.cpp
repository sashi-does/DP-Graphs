// https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        // relaxation for V - 1 times
        for(int i = 0; i < V - 1; i++) {
            for(auto &edge : edges) {
                int u = edge[0], v = edge[1], wt = edge[2];
                if(dist[u] == 1e8) continue;
                if(dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        // detection of negative cycle
        for(auto &edge : edges) {
                int u = edge[0], v = edge[1], wt = edge[2];
                if(dist[u] == 1e8) continue;
                if(dist[u] + wt < dist[v]) {
                    return {-1};
                }
            }
        return dist;
        
    }
};
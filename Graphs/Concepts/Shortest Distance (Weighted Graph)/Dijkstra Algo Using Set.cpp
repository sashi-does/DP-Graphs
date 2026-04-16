// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>> adj(V);
        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        set<pair<int, int>> s;
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        s.insert({0, src});
        while(!s.empty()) {
            auto it = s.begin();
            int currDist = it->first, currNode = it->second;
            s.erase(it);
            if(dist[currNode] < currDist)
                continue;
            for(auto curr : adj[currNode]) {
                int wt = curr.second;
                int node = curr.first;
                if(wt + currDist < dist[node]) {
                    dist[node] = wt + currDist;
                    s.insert({dist[node], node});
                }
            }
        }
        return dist;
        
    }
};
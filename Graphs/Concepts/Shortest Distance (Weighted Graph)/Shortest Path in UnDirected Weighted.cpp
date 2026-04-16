// https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1
// BFS will not work for finding the shortest path since here path is dependent on the weights
// If the weights of the edges of the graph is unity then we can apply BFS

typedef pair<int, int> T;
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<T>> adj(n + 1);
        for(int i = 0; i < m; i++) {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        priority_queue<T, vector<T>, greater<T>> pq;
        vector<int> parent(n + 1, -1);
        for(int i = 0; i <= n; i++)
            parent[i] = i;
        vector<int> dist(n + 1, INT_MAX);
        // dist, node
        pq.push({0, 1});
        dist[1] = 0;
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int node = top.second, d = top.first;
            if(d > dist[node]) continue;
            for(auto &p : adj[node]) {
                int neighNode = p.first, neighDist = p.second;
                if(neighDist + d < dist[neighNode]) {
                    dist[neighNode] = neighDist + d;
                    pq.push({dist[neighNode], neighNode});
                    parent[neighNode] = node;
                }
            }
        }
        if(dist[n] == INT_MAX) return {-1};
        stack<int> stk;
        int pos = n;

        while(pos != parent[pos]) {
            stk.push(pos);
            pos = parent[pos];
        }
        stk.push(1);
        vector<int> path;
        
        while(!stk.empty()) {
            path.push_back(stk.top());
            stk.pop();
        }
        path.insert(path.begin(), dist[n]);
        return path;
    }
};
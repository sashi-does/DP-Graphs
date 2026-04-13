// https://leetcode.com/problems/network-delay-time/

typedef pair<int, int> T;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<T>> adj(n + 1);
        int u, v, w, node, d, neighNode, neighDist, maxDist = -1;
        for(auto &edges : times) {
            u = edges[0], v = edges[1], w = edges[2];
            adj[u].push_back({v, w});
        }
        vector<int> dist(n + 1, INT_MAX);
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push({0, k});
        dist[k] = 0;
        while(!pq.empty()) {
            T front = pq.top();
            node = front.second, d = front.first;
            pq.pop();
            for(T pairs : adj[node]) {
                neighNode = pairs.first, neighDist = pairs.second;
                if(neighDist + d < dist[neighNode]) {
                    dist[neighNode] = neighDist + d;
                    pq.push({dist[neighNode], neighNode});
                }
            }
        }

        for(int i = 1; i <= n; i++) {
            d = dist[i];
            if(d == INT_MAX)
                return -1;
            maxDist = max(maxDist, d);
        }
        return maxDist;
    }
};
// https://leetcode.com/problems/min-cost-to-connect-all-points/description/

typedef pair<int, int> T;
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int v = points.size();
        vector<vector<T>> adj(v);
        vector<bool> visited(v, false);
        for(int i = 0; i < v; i++) {
            for(int j = i + 1; j < v; j++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                
                adj[i].push_back({j, abs(x1 - x2) + abs(y1 - y2)});
                adj[j].push_back({i, abs(x1 - x2) + abs(y1 - y2)});
            }
        }
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push({0, 0});
        int cost = 0;
        while(!pq.empty()) {
            auto [wt, node] = pq.top();
            pq.pop();
            if(visited[node])
                continue;
            cost += wt;
            visited[node] = true;
            for(auto p : adj[node]) {
                auto [curr_node, curr_wt] = p;
                if(!visited[curr_node]) {
                    pq.push({curr_wt, curr_node});
                }
            }
        }
        return cost;
    }
};
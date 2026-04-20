// https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees/description/

class Solution {
public:
    vector<vector<int>> adj1;
    vector<vector<int>> adj2;
    pair<int, int> BFS(vector<vector<int>>& adj, int src) {
        queue<int> q;
        vector<bool> visited(adj.size() + 1, false);
        q.push(src);
        visited[src] = true;
        int level = -1, diameterEnd = src;
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                int front = q.front();
                diameterEnd = front;
                q.pop();
                for(int node : adj[front]) {
                    if(!visited[node]) {
                        q.push(node);
                        visited[node] = true;
                    }
                }
            }
            level++;
        }
        return {level, diameterEnd};
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        adj1.resize(edges1.size() + 1);
        adj2.resize(edges2.size() + 1);

        for(int i = 0; i < edges1.size(); i++) {
            adj1[edges1[i][0]].push_back(edges1[i][1]);
            adj1[edges1[i][1]].push_back(edges1[i][0]);
        }
        for(int i = 0; i < edges2.size(); i++) {
            adj2[edges2[i][0]].push_back(edges2[i][1]);
            adj2[edges2[i][1]].push_back(edges2[i][0]);
        }

        auto [d1, n1] = BFS(adj1, 0);
        auto [d2, n2] = BFS(adj1, n1);

        int d = (d2 + 1) / 2;

        auto [d3, n3] = BFS(adj2, 0);
        auto [d4, n4] = BFS(adj2, n3);
        
        int d_ = (d4 + 1) / 2;
        int res = (d + d_ + 1);

        return max({res, d2, d4});
    }
};
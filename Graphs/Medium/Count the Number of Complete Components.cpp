// https://leetcode.com/problems/count-the-number-of-complete-components

class Solution {
public:
    vector<bool> visited;
    bool isComplete(int node, vector<vector<int>>& graph) {
        queue<int> q;
        unordered_map<int, int> track;
        int cmp = 1;

        q.push(node);
        visited[node] = true;


        while(!q.empty()) {
            int front = q.front();
            track[front] = (int)graph[front].size();
            q.pop();
            for(int curr : graph[front]) {
                if(!visited[curr]) {
                    q.push(curr);
                    cmp++;
                    visited[curr] = true;
                }
            }
        }

        for(auto &it : track) {
            if(track[it.first] != cmp - 1)
                return false;
        }
        return true;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // every node has n - 1 neighbours
        vector<vector<int>> adj(n);
        visited.resize(n, false);
        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        int comp = 0;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                if(isComplete(i, adj))
                    comp++;
            }
        }
        return comp;
    }
};
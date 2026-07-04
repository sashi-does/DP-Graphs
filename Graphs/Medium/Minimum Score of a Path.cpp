// https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities

/*
Time Spent: 37min

LESSON: try to think when do you need visited and when do you need to track shortest distance that acts as visited. If you figure this try to go for the invariant of the problem and parameters have to be taken for the queue
*/

class Solution {
public:
    int globalMinWt = INT_MAX;
    vector<int> dist;
    void bfs(int node, vector<vector<pair<int, int>>>& adj, int n) {
        int minWt = INT_MAX;
        queue<int> q;
        q.push(node);
        // vector<bool> visited(n + 1, false);
        // visited[node] = true;
        bool stats = false;
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            if(front == n)
                stats = true;
            for(pair<int, int> neigh : adj[front]) {
                minWt = min(minWt, neigh.second);
                if(dist[neigh.first] > minWt) {
                    // visited[neigh.first] = true;
                    q.push(neigh.first);
                    dist[neigh.first] = minWt;
                }
            }
        }
        if(stats)
            globalMinWt = min(globalMinWt, minWt);

    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<bool> visited(n + 1, false);
        vector<vector<pair<int, int>>> adj(n + 1);
        dist.resize(n + 1, INT_MAX);
        for(int i = 0; i < roads.size(); i++) {
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        for(int i = 1; i <= n; i++) {
            if(!visited[i]) {
                bfs(i, adj, n);
            } 
        }
        return globalMinWt;
    }
};
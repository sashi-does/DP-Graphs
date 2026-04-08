// https://leetcode.com/problems/is-graph-bipartite/

class Solution {
public:
    vector<int> colors;
    int n;
    bool BFS(vector<vector<int>>& graph, int node, int color) {
        queue<int> q;
        q.push(node);
        colors[node] = color;
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            for(int &n : graph[front]) {
                if(colors[n] == colors[front]) 
                    return false;
                if(colors[n] == -1) {
                    colors[n] = 1 - colors[front];
                    q.push(n);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        n = graph.size();
        colors = vector<int>(n, -1);
        for(int i = 0; i < n; i++) {
            if(colors[i] == -1 && !BFS(graph, i, 0)) {
                return false;
            }
        }
        return true;
    }
};
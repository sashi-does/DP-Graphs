// https://leetcode.com/problems/is-graph-bipartite/

class Solution {
public:
    vector<int> colors;
    int n;
    bool DFS(vector<vector<int>>& graph, int node, int color) {
        colors[node] = color;
        for(int n : graph[node]) {
            if(colors[n] == color)
                return false;
            if(colors[n] == -1 && !DFS(graph, n, 1 - color))
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        n = graph.size();
        colors = vector<int>(n, -1);
        for(int i = 0; i < n; i++) {
            if(colors[i] == -1 && !DFS(graph, i, 0)) {
                return false;
            }
        }
        return true;
    }
};
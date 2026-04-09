// https://leetcode.com/problems/all-paths-from-source-to-target/description/

class Solution {
public:
    vector<int> path;
    vector<vector<int>> paths;
    vector<bool> visited;
    int v;
    void dfs(int node, vector<vector<int>>& graph) {
        visited[node] = true;
        path.push_back(node);
        if(node == v - 1) {
            paths.push_back(path);
        }
        for(int n : graph[node]) {
            if(!visited[n]) {
                dfs(n, graph);
            }
        }
        path.pop_back();
        visited[node] = false;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        v = graph.size();
        visited = vector<bool>(v, false);
        dfs(0, graph);
        return paths;
    }
};
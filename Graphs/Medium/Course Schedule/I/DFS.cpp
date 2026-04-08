// https://leetcode.com/problems/course-schedule/

class Solution {
public:
    vector<bool> visited;
    bool dfs(vector<vector<int>>& adj, int n, vector<bool>& inRecursion) {
        inRecursion[n] = true;
        visited[n] = true;
        for(int node : adj[n]) {
            if(inRecursion[node])
                return true;
            if(!visited[node] && dfs(adj, node, inRecursion))
                return true;
        }
        inRecursion[n] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        visited = vector<bool>(numCourses, false);
        vector<vector<int>> adj(numCourses);
        for(int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i = 0; i < numCourses; i++) {
            vector<bool> inRecursion(numCourses, false);
            if(!visited[i] && dfs(adj, i, inRecursion)) {
                visited[i] = true;
                return false;
            }
        }
        return true;
    }
};
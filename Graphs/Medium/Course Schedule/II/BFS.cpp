// https://leetcode.com/problems/course-schedule-ii/description/

class Solution {
public:
    vector<int> chron;
    void topoSort(vector<vector<int>>& adj, vector<int>& inDegree) {
        queue<int> q;
        for(int i = 0; i < inDegree.size(); i++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int front = q.front();
            chron.push_back(front);
            q.pop();
            for(int node : adj[front]) {
                inDegree[node]--;
                if(inDegree[node] == 0) 
                    q.push(node);
            }
        }
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);
        for(int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegree[prerequisites[i][0]]++;
        }

        topoSort(adj, inDegree);
        if(chron.size() == numCourses)
            return chron;
        return {};
    }
};
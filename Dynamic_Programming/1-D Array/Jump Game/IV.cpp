// https://leetcode.com/problems/jump-game-iv/

class Solution {
public:
    int minJumps(vector<int>& arr) {

        int n = arr.size();
        unordered_map<int, unordered_set<int>> adj;
        for(int i = 0; i < n; i++) {
            adj[arr[i]].insert(i);
        }
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int steps = -1;
        while(!q.empty()) {
            int sz = q.size();
            steps++;
            for(int i = 0; i < sz; i++) {
                int pos = q.front();
                q.pop();
                if(pos == n - 1) {
                    return steps;
                }
                 if(pos + 1 < n && !visited[pos + 1]) {
                    visited[pos + 1] = true;
                    q.push(pos + 1);
                }
                if(pos - 1 >= 0 && !visited[pos - 1]) {
                    visited[pos - 1] = true;
                    q.push(pos - 1);
                }
                for(int idx : adj[arr[pos]]) {
                    if(!visited[idx]) {
                        visited[idx] = true;
                        q.push(idx);
                    }
                   
                }
                adj[arr[pos]].clear();
            }
        }
        return steps;
    }
};
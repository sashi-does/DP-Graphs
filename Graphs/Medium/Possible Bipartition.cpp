// https://leetcode.com/problems/possible-bipartition/

class Solution {
public:
    vector<tuple<bool, int>> visited;
    vector<vector<int>> adj;
    bool BFS(int node) {
        // node color
        queue<tuple<int, int>> q;
        q.push({node, 0});
        get<0>(visited[node]) = true;
        get<1>(visited[node]) = 0;

        while(!q.empty()) {
            auto [currNode, color] = q.front();
            q.pop();
            for(int n : adj[currNode]) {
                if(get<0>(visited[n]) == false) {
                    get<0>(visited[n]) = true;
                    get<1>(visited[n]) = 1 - color;
                    q.push({n, 1 - color});
                }
                else {
                    if(color == get<1>(visited[n])) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        adj.resize(n + 1);
        visited.resize(n + 1, {false, -1});
        for(int i = 0; i < dislikes.size(); i++) {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);

        }
        for(int i = 1; i <= n; i++) {
            if(get<0>(visited[i]) == false) {
               if(!BFS(i)) return false;
            }
        }
        return true;
    }
};
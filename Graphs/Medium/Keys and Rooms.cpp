// https://leetcode.com/problems/keys-and-rooms/

class Solution {
public:
    vector<bool> visited;
    void DFS(int i, vector<vector<int>>& adj) {
        visited[i] = true;
        for(int node : adj[i]) {
            if(!visited[node]) {
                DFS(node, adj);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        visited.resize(n, false);
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++) {
            for(auto &roomNo : rooms[i]) 
                adj[i].push_back(roomNo);
        }
        int components = 0;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                DFS(i, adj);
                components++;
                if(components >= 2) break;
            }
        }
        return components == 1;

    }
};
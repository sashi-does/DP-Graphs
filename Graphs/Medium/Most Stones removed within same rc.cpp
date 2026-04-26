// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/

class Solution {
public:
    vector<bool> visited;
    void DFS(vector<vector<int>>& stones, int idx) {
        visited[idx] = true;
        for(int i = 0; i < stones.size(); i++) {
            if(!visited[i]) {
                if(stones[idx][0] == stones[i][0] || stones[idx][1] == stones[i][1]) {
                    DFS(stones, i);
                }
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        visited.resize(n, false);
        int components = 0;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                DFS(stones, i);
                components++;
            }
        }
        return n - components;
        
    }
};
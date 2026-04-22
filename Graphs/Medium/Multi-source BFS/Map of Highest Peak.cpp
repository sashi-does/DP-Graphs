// https://leetcode.com/problems/map-of-highest-peak/description/

class Solution {
public:
    int m, n;
    typedef tuple<int, int, int> T;
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<T> q;
        m = isWater.size(), n = isWater[0].size();
        int x, y;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        // start BFS from 1 cell and mark that cell's value as 0
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(isWater[i][j] == 1) {
                    isWater[i][j] = 0;
                    visited[i][j] = true;
                    q.push({i, j, 0});
                }
            }
        }
        while(!q.empty()) {
            auto [curr_x, curr_y, height] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
                x = curr_x + dx[i], y = curr_y + dy[i];
                if(x >= 0 && x < m && y >= 0 && y < n && !visited[x][y]) {
                    q.push({x, y, height + 1});
                    visited[x][y] = true;
                    isWater[x][y] = height + 1;
                }
            }
        }
        return isWater;

    }
};
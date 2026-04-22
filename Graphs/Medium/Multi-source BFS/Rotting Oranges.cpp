// https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<tuple<int, int, int>> q;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j, 0});
                    grid[i][j] = 0; 
                }
            }
        }
        int x, y, minutes = 0;
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                auto [curr_x, curr_y, time] = q.front();
                minutes = time;
                q.pop();
                for(int t = 0; t < 4; t++) {
                    x = curr_x + dx[t], y = curr_y + dy[t];
                    if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != 0) {
                        grid[x][y] = 0;
                        q.push({x, y, time + 1});
                    } 
                }
                
            }
            
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1)
                    return -1;
            }
        }
        return minutes;
    }
};

// https://leetcode.com/problems/detect-cycles-in-2d-grid/description

class Solution {
public:
    vector<vector<bool>> visited;
    int m, n;
    vector<int> xc = {1, -1, 0, 0};
    vector<int> yc = {0, 0, 1, -1};


    bool isValid(int x, int y, vector<vector<char>>& grid, char c) {
        return ((x >= 0 && x < m) && (y >= 0 && y < n) && (grid[x][y] == c));
    }
    bool BFS(int curr_x, int curr_y, vector<vector<char>>& grid) {
        queue<tuple<int, int,int, int>> q;
        q.push({curr_x, curr_y, -1, -1});
        visited[curr_x][curr_y] = true;
        int x, y;
        visited[curr_x][curr_y] = true;
        while(!q.empty()) {
            auto [_x, _y, x_par, y_par] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
                x = _x + xc[i];
                y = _y + yc[i];
                if(isValid(x, y, grid, grid[curr_x][curr_y])) {
                     if(!visited[x][y]) {
                        visited[x][y] = true;
                        q.push({x, y, _x, _y});
                    }
                    else if(x != x_par || y != y_par) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false)); 
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] && BFS(i, j, grid)) 
                    return true;
            }
        }
        return false;
    }
};
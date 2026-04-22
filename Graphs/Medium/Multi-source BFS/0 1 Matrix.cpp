class Solution {
public:
    typedef tuple<int, int, int> T;
    int m, n;
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<T> q;
        m = mat.size(), n = mat[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) 
                    q.push({i, j, 0});
            }
        }
        int x, y;
        while(!q.empty()) {
            auto [curr_x, curr_y, step] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
                x = curr_x + dx[i], y = curr_y + dy[i];
                if(x >= 0 && x < m && y >= 0 && y < n && !visited[x][y]) {
                    if(mat[x][y] == 1) {
                        mat[x][y] = step + 1;
                        visited[x][y] = true;
                        q.push({x, y, step + 1});
                    }
                }
            }
        }
        return mat;
    }
};
// https://leetcode.com/problems/shortest-path-in-binary-matrix/description/
// Regular BFS works since the weights of all the sides are 1
// Even Dijkstra's Algorithm works (For every shortest Path)

typedef pair<pair<int, int>, int> T; 
class Solution {
public:
    int m, n;
    vector<int>x = {1, 0, -1, 0, 1, 1, -1, -1};
    vector<int>y = {0, 1, 0, -1, 1, -1, 1, -1};
    int BFS(vector<vector<int>>& grid) {
        int minDist = INT_MAX;
        queue<T> q;
        q.push({{0, 0}, 1});
        vector<vector<int>> visited(m, vector<int>(n, -1));
        visited[0][0] = 1;
        while(!q.empty()) {
            auto [curr_x, curr_y] = q.front().first;
            int dist = q.front().second;
            q.pop();
            if(curr_x == m - 1 && curr_y == n - 1) {
                minDist = min(minDist, dist);
            }
            for(int i = 0; i < 8; i++) {
                int mod_x = curr_x + x[i], mod_y = curr_y + y[i];
                if((mod_x >= 0 && mod_x < m) && (mod_y >= 0 && mod_y < n) && (grid[mod_x][mod_y] == 0) && (visited[mod_x][mod_y] == -1)) {
                    q.push({{mod_x, mod_y}, dist + 1});
                    visited[mod_x][mod_y] = 1;
                }
            }

            // if(x + 1 < m && visited[x + 1][y] == -1 && grid[x + 1][y] == 0) {
            //     q.push({{x + 1, y}, dist + 1});
            //     visited[x + 1][y] = 1;
            // }
            // if(y + 1 < n && visited[x][y + 1] == -1 && grid[x][y + 1] == 0) {
            //     q.push({{x, y + 1}, dist + 1});
            //     visited[x][y + 1] = 1;
            // }
            // if(x - 1 >= 0 && visited[x - 1][y] == -1 && grid[x - 1][y] == 0) {
            //     q.push({{x - 1, y}, dist + 1});
            //     visited[x - 1][y] = 1;
            // }
            // if(y - 1 >= 0 && visited[x][y - 1] == -1 && grid[x][y - 1] == 0) {
            //     q.push({{x, y - 1}, dist + 1});
            //     visited[x][y - 1] = 1;
            // }
            // if(x + 1 < m && y + 1 < n && visited[x + 1][y + 1] == -1 && grid[x + 1][y + 1] == 0) {
            //     q.push({{x + 1, y + 1}, dist + 1});
            //     visited[x + 1][y + 1] = 1;
            // }
            // if(x + 1 < n && y - 1 >= 0 && visited[x + 1][y - 1] == -1 && grid[x + 1][y - 1] == 0) {
            //     q.push({{x + 1, y - 1}, dist + 1});
            //     visited[x + 1][y - 1] = 1;
            // }
            // if(x - 1 >= 0 && y + 1 < n && visited[x - 1][y + 1] == -1 && grid[x - 1][y + 1] == 0) {
            //     q.push({{x - 1, y + 1}, dist + 1});
            //     visited[x - 1][y + 1] = 1;
            // }
            // if(x - 1 >= 0 && y - 1 >= 0 && visited[x - 1][y - 1] == -1 && grid[x - 1][y - 1] == 0) {
            //     q.push({{x - 1, y - 1}, dist + 1});
            //     visited[x - 1][y - 1] = 1;
            // }
        }
        return minDist == INT_MAX ? -1 : minDist;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        if(grid[0][0] == 1 || grid[m - 1][n - 1] == 1) return -1;
        return BFS(grid); 
    }
};
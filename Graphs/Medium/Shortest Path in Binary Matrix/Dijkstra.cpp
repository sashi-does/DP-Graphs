// https://leetcode.com/problems/shortest-path-in-binary-matrix/

typedef pair<int, pair<int, int>> T; 

class Solution {
public:
    int m, n;
    vector<int>xc = {1, 0, -1, 0, 1, 1, -1, -1};
    vector<int>yc = {0, 1, 0, -1, 1, -1, 1, -1};
    bool isValid(int x, int y, vector<vector<int>>& grid) {
        return (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 0);
    }
    int Dijkstra(vector<vector<int>>& grid) {
        priority_queue<T, vector<T>, greater<T>> pq;
        int x, y;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        pq.push({1, {0, 0}});
        dist[0][0] = 1;
        while(!pq.empty()) {
            T front = pq.top();
            pq.pop();
            auto [curr_x, curr_y] = front.second;
            int curr_wt = front.first;
            for(int i = 0; i < 8; i++) {
                x = curr_x + xc[i], y = curr_y + yc[i];
                if(isValid(x, y, grid)) {
                    if(dist[x][y] > curr_wt + 1) {
                        dist[x][y] = curr_wt + 1;
                        pq.push({dist[x][y], {x, y}});
                    }
                }
            }
        }
     
        return dist[m - 1][n - 1] == INT_MAX ? -1 : dist[m - 1][n - 1];

    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        if(grid[0][0] == 1 || grid[m - 1][n - 1] == 1) return -1;
        return Dijkstra(grid);
    }
};
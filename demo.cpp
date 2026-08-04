/*
Author: sashi-does
date: 31 july, 2026

"A year from now, you'll wish you had started today."
*/

// Given a matrix of size n x m. An island is defined as a group of connected cells, each cell having a non-zero value, and each cell should have at least one adjacent cell having non-zero value.
// Water cells have mat[i][j] = 0, and land cells have mat[i][j] != 0.
// The boundary score of an island is the sum of mat[i][j], where cell (i, j) is a cell in the island and it has water on at least one of its 4 sides. Assume there is water outside the grid.
// You have to find how many islands have boundary score divisible by k.

// Input:
// k = 2
// grid = [[1,1,1],[2,2,2],[3,4,0]]

// Output:
// 1


#include <bits/stdc++.h>
using namespace std;

bool isBound(int x, int y, vector<vector<int>>& grid, int m, int n) {
    if(x == 0 || y == 0 || x == m - 1 || y == n - 1)
        return true;
    if(x - 1 >= 0 && grid[x - 1][y] == 0)
        return true;
    if(y - 1 >= 0 && grid[x][y - 1] == 0)
        return true;
    if(x + 1 < m && grid[x + 1][y] == 0)
        return true;
    if(y + 1 < n && grid[x][y + 1] == 0)
        return true;
    return false;
}

int bfs(vector<vector<bool>> &visited, vector<vector<int>>& grid, int i, int j, int m, int n) {
    queue<pair<int, int>> q;
    int tot = isBound(i, j, grid, m, n) ? grid[i][j] : 0;
    q.push({i, j});
    visited[i][j] = true;

    while(!q.empty()) {
        pair<int, int> top = q.front();
        q.pop();
        int x = top.first, y = top.second;
        if(x - 1 >= 0 && !visited[x - 1][y] && grid[x - 1][y] != 0) {
            q.push({x - 1, y});
            visited[x - 1][y] = true;
            if(isBound(x - 1, y, grid, m, n))
                tot += grid[x - 1][y];
        }
        if(x + 1 < m && !visited[x + 1][y] && grid[x + 1][y] != 0) {
            q.push({x + 1, y});
            visited[x + 1][y] = true;
            if(isBound(x + 1, y, grid, m, n))
                tot += grid[x + 1][y];
        }
        if(y - 1 >= 0 && !visited[x][y - 1] && grid[x][y - 1] != 0) {
            q.push({x, y - 1});
            visited[x][y - 1] = true;
            if(isBound(x, y - 1, grid, m, n))
                tot += grid[x][y - 1];
        }
        if(y + 1 < n && !visited[x][y + 1] && grid[x][y + 1] != 0) {
            q.push({x, y + 1});
            visited[x][y + 1] = true;
            if(isBound(x, y + 1, grid, m, n))
                tot += grid[x][y + 1];
        }
    }

    return tot;
}

signed main() {

    int t;
    cin >> t;

    while(t--) {

        int m, n, k;
        cin >> m >> n >> k;
        vector<vector<int>> grid(m, vector<int>(n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++)
                cin >> grid[i][j];
        }

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int cnt = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] && grid[i][j] != 0) {
                    if(bfs(visited, grid, i, j, m, n) % k == 0)
                        cnt++;
                }
            }
        }

        cout << cnt << endl;
    }

    return 0;
}
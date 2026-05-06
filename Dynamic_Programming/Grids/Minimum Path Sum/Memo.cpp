// https://leetcode.com/problems/minimum-path-sum/description/

class Solution {
public:
    int minSum;
    vector<vector<int>> dp;
    int m, n;
    int backtrack(int x, int y, vector<vector<int>>& grid) {
        if(x >= m || x < 0 || y >= n || y < 0)
            return INT_MAX;
        if(x == m - 1 && y == n - 1) {
            return grid[x][y];
        }
        if(dp[x][y] != -1)
            return dp[x][y];
        int bottom = backtrack(x + 1, y, grid);
        int right = backtrack(x, y + 1, grid);
        return dp[x][y] = grid[x][y] + min(bottom, right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        dp.resize(m, vector<int>(n, -1));
        return backtrack(0, 0, grid);
    }
};
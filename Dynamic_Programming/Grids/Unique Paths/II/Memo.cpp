// https://leetcode.com/problems/unique-paths-ii/

class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    int backtrack(int x, int y, vector<vector<int>>& obstacleGrid) {
        if(x >= m || x < 0 || y >= n || y < 0 || obstacleGrid[x][y] == 1) 
            return 0;
        if(dp[x][y] != -1)
            return dp[x][y];
        if(x == m - 1 && y == n - 1)
            return 1;
        int right = backtrack(x, y + 1, obstacleGrid);
        int bottom = backtrack(x + 1, y, obstacleGrid);
        return dp[x][y] = right + bottom;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1)
            return 0;
        dp.resize(m, vector<int>(n, -1));
        return backtrack(0, 0, obstacleGrid);
    }
};
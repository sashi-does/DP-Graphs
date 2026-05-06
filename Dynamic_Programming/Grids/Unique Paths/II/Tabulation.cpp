// https://leetcode.com/problems/unique-paths-ii/

class Solution {
public:
    int m, n;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1)
            return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            if(obstacleGrid[i][0] == 0) dp[i][0] = 1;
            else break;
        }
        for(int j = 0; j < n; j++) {
            if(obstacleGrid[0][j] == 0) dp[0][j] = 1;
            else break;
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                int fromTop = (obstacleGrid[i - 1][j] == 0 ? dp[i - 1][j] : 0);
                int fromLeft = (obstacleGrid[i][j - 1] == 0 ? dp[i][j - 1] : 0);
                dp[i][j] = fromTop + fromLeft;
            }
        }
        return dp[m - 1][n - 1];
    }
};
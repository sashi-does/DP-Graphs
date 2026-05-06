// https://leetcode.com/problems/unique-paths/description/

class Solution {
public:
    vector<vector<int>> dp;
    int uniquePaths(int m, int n) {
        dp.resize(m, vector<int>(n, 0));
        
        dp[0][0] = 1; // total ways to reach (0, 0) from (0, 0) is 1 (i.e stay in that cell)

        for(int i = 1; i < m; i++)
            dp[i][0] = 1;
        for(int i = 1; i < n; i++)
            dp[0][i] = 1;
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
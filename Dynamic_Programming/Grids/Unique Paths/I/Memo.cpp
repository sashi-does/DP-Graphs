// https://leetcode.com/problems/unique-paths/description/

class Solution {
public:
    vector<vector<int>> dp;
    int backtrack(int x, int y) {
        if(x >= dp.size() || x < 0 || y >= dp[0].size() || y < 0)
            return 0;
        if(x == dp.size() - 1 && y == dp[0].size() - 1)
            return 1;
        if(dp[x][y] != -1)
            return dp[x][y];
        int right = backtrack(x, y + 1);
        int down = backtrack(x + 1, y);
        return dp[x][y] = right + down;
    }
    int uniquePaths(int m, int n) {
        dp.resize(m, vector<int>(n, -1));
        return backtrack(0, 0);
    }
};
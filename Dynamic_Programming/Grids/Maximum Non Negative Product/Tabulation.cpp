// https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/

class Solution {
public:
    int m, n;
    vector<vector<pair<long long, long long>>> dp;
    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        dp.resize(m, vector<pair<long long, long long>>(n, {LLONG_MAX, LLONG_MIN}));
        int MOD = 1e9 + 7;

        dp[0][0] = {grid[0][0], grid[0][0]};
        for(int i = 1; i < m; i++) {
            long long maxVal = dp[i - 1][0].first, minVal = dp[i - 1][0].second;
            dp[i][0] = {
                max(maxVal * grid[i][0], minVal * grid[i][0]),
                min(minVal * grid[i][0], minVal * grid[i][0])
            };

        }
        for(int j = 1; j < n; j++) {
            long long maxVal = dp[0][j - 1].first, minVal = dp[0][j - 1].second;
            dp[0][j] = {
                max(maxVal * grid[0][j], minVal * grid[0][j]),
                min(minVal * grid[0][j], minVal * grid[0][j])
            };
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                long long maxVal = LLONG_MIN, minVal = LLONG_MAX;
                pair<long long, long long> top = dp[i - 1][j];
                pair<long long, long long> left = dp[i][j - 1]; 
                // 

                maxVal = max({maxVal, grid[i][j] * top.first, grid[i][j] * top.second});
                minVal = min({minVal, grid[i][j] * top.first, grid[i][j] * top.second});

                maxVal = max({maxVal, grid[i][j] * left.first, grid[i][j] * left.second});
                minVal = min({minVal, grid[i][j] * left.first, grid[i][j] * left.second});

                dp[i][j] = {maxVal, minVal};
            }
        }

        return dp[m - 1][n - 1].first % MOD < 0 ? -1 : dp[m - 1][n - 1].first % MOD;
    }
};
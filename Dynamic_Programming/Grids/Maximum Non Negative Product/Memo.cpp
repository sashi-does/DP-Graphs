// https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/

class Solution {
public:
    int m, n;
    vector<vector<pair<long long, long long>>> dp;
    pair<long long, long long> backtrack(int x, int y, vector<vector<int>>& grid) {
        if(x == m - 1 && y == n - 1)
            return {grid[x][y], grid[x][y]};
        if(dp[x][y].first != LLONG_MIN && dp[x][y].second != LLONG_MIN) {
            return dp[x][y];
        }
        long long maxVal = LONG_MIN, minVal = LONG_MAX;
        if(x + 1 < m) {
            auto [downMax, downMin] = backtrack(x + 1, y, grid);
            maxVal = max({maxVal, downMax * grid[x][y] * 1LL, downMin * grid[x][y] * 1LL});
            minVal = min({minVal, downMin * grid[x][y] * 1LL, downMax * grid[x][y] * 1LL});
        }
        if(y + 1 < n) {
            auto [rightMax, rightMin] = backtrack(x, y + 1, grid);
            maxVal = max({maxVal, rightMax * grid[x][y] * 1LL, rightMin * grid[x][y] * 1LL});
            minVal = min({minVal, rightMin * grid[x][y] * 1LL, rightMax * grid[x][y] * 1LL});
        }
        return dp[x][y] = {maxVal, minVal};
    }
    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        dp.resize(m, vector<pair<long long, long long>>(n, {LLONG_MIN, LLONG_MIN}));
        pair<long long, long long> res = backtrack(0, 0, grid);
        long long maxProd = max(res.first, res.second), MOD = 1e9 + 7;
        return maxProd < 0 ? -1 : maxProd % MOD;
        
    }
};
// https://leetcode.com/problems/domino-and-tromino-tiling/description/

class Solution {
public:
    int numTilings(int n) {
        if(n <= 3) {
            if(n <= 2) return n;
            return 5;
        }
        vector<int> dp(n + 1, 0);
        int MOD = 1e9 + 7;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        // dp[4] = 11 == 2*dp[3] + dp[1];
        for(int i = 4; i <= n; i++) {
            dp[i] = ((2 * dp[i - 1]) % MOD + dp[i - 3]) % MOD;
        }

        return dp[n];
    }
};
// https://leetcode.com/problems/coin-change-ii/

class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int backtrack(vector<int>& coins, int amount, int idx) {
        if(amount == 0)
            return 1;
        if(idx < 0 || amount < 0)
            return 0;
        if(dp[idx][amount] != -1)
            return dp[idx][amount];
        int pick = 0, notPick = 0;
        if(amount - coins[idx] >= 0) {
            pick = backtrack(coins, amount - coins[idx], idx);
        }
        notPick = backtrack(coins, amount, idx - 1);
        return dp[idx][amount] = pick + notPick;
    }
    int change(int amount, vector<int>& coins) {
        n = coins.size();
        dp.resize(n, vector<int>(amount + 1, -1));
        return backtrack(coins, amount, n - 1);
    }
};
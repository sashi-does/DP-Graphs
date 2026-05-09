// https://leetcode.com/problems/coin-change/

class Solution {
public:
    int n;
    vector<vector<long long>> dp;
    long long backtrack(vector<int>& coins, int amount, int idx) {
        if(idx < 0 || amount < 0)
            return INT_MAX;
        if(amount == 0)
            return 0;
        if(dp[idx][amount] != -1)
            return dp[idx][amount];
        long long curr = INT_MAX;
        if(amount - coins[idx] >= 0) {
            curr = 1 + backtrack(coins, amount - coins[idx], idx);
        }
        curr = min(curr, backtrack(coins, amount, idx - 1));
        return dp[idx][amount] = curr;
    }
    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        dp.resize(n, vector<long long>(amount + 1, -1));
        long long res = backtrack(coins, amount, n - 1);
        return res == INT_MAX ? -1 : res; 
    }
};
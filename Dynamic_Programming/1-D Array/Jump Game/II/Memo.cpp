// https://leetcode.com/problems/jump-game-ii/description/

class Solution {
public:
    vector<int> dp;
    long long backtrack(int idx, vector<int>& nums) {
        if(idx >= nums.size() - 1)
            return 0;
        if(dp[idx] != -1)
            return dp[idx];
        long long steps = INT_MAX;
        for(int i = 1; i <= nums[idx]; i++) {
            steps = min(steps, 1 + backtrack(idx + i, nums));
        }
        return dp[idx] = steps;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, -1);
        int res = backtrack(0, nums); 
        return res  == INT_MAX ? 0 : res;

    }
};
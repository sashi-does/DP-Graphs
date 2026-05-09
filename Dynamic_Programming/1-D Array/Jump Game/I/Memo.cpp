// https://leetcode.com/problems/jump-game/description/

class Solution {
public:
    vector<int> dp;
    bool backtrack(vector<int>& nums, int idx) {
        if(idx >= nums.size() - 1)
            return true;
        if(dp[idx] != -1)
            return dp[idx];
        for(int i = 1; i <= nums[idx]; i++) {
            if(backtrack(nums, idx + i)) {
                return dp[idx + i] = true;
            }
        }
        return dp[idx] = false;
    }
    bool canJump(vector<int>& nums) {
        dp.resize(nums.size(), -1);
        return backtrack(nums, 0);
    }
};
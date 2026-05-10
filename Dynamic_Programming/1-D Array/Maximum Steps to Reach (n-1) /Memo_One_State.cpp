// https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/description/

class Solution {
public:
    vector<int> dp;
    int backtrack(vector<int>& nums, int target, int idx) {
        if(idx == nums.size() - 1)
            return dp[idx] = 0;
        if(dp[idx] != -69)
            return dp[idx];
        int maxJump = INT_MIN, steps;
        for(int i = idx + 1; i < nums.size(); i++) {
            if(abs(nums[i] - nums[idx]) <= target) {
                steps = 1 + backtrack(nums, target, i);
                maxJump = max(steps, maxJump);
            }
        }
        return dp[idx] = maxJump;
    }
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        
        dp.resize(n, -69);
        int res = backtrack(nums, target, 0);
        return res < 0 ? -1 : res;
    }
};
// https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/description/

class Solution {
public:
    vector<vector<int>> dp;
    bool isValid(int prev, int curr, int target, vector<int>& nums) {
        return nums[curr] - nums[prev] <= target && 
                -target <= nums[curr] - nums[prev];
    }
    int backtrack(vector<int>& nums, int target, int prev, int curr) {
        if(curr == nums.size() - 1) {
            if(isValid(prev, curr, target, nums)) 
                    return 1;
            return INT_MIN;
        }
        if(dp[prev][curr] != -69) {
            return dp[prev][curr];
        }
        if(dp[curr][prev] != -69) {
            return dp[curr][prev];
        }
        int jump = INT_MIN, not_jump = INT_MIN;
        if(isValid(prev, curr, target, nums)) {
            int res = backtrack(nums, target, curr, curr + 1);
            if(res != INT_MIN)
                jump = 1 + res;
        }
        not_jump = backtrack(nums, target, prev, curr + 1);
        dp[curr][prev] = max(jump, not_jump);
        return dp[prev][curr] = max(jump, not_jump);
    }
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        dp.resize(n, vector<int>(n, -69));
        int res = backtrack(nums, target, 0, 1);
        return res  == INT_MIN ? -1 : res;
    }
};
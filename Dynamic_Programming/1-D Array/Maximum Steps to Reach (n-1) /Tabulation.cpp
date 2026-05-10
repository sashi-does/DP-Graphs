// https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/description/

class Solution {
public:
    vector<int> dp;
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        
        dp.resize(n + 1, -69);
        dp[n - 1] = 0;
        for(int i = n - 2; i >= 0; i--) {
            int maxJump = INT_MIN;
            for(int j = i + 1; j < n; j++) {
                if(abs(nums[i] - nums[j]) <= target) {
                    maxJump = max(maxJump, 1 + dp[j]);
                }
            }
            dp[i] = maxJump;
        }
        return dp[0] >= 0 ? dp[0] : -1;
    }
};
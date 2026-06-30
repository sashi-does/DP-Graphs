// https://www.geeksforgeeks.org/problems/stickler-theif-1587115621/1

class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = max(arr[0], 0);
        dp[2] = max({arr[0], arr[1], 0});
        
        for(int i = 3; i <= n; i++) {
            dp[i] = max(dp[i - 1], arr[i - 1] + dp[i - 2]);
        }
        
        return dp[n];
        
    }
};
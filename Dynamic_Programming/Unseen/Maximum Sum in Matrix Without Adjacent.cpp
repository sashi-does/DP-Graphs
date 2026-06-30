// https://www.geeksforgeeks.org/problems/adjacents-are-not-allowed3528/1

class Solution {
  public:
    int maxSum(vector<vector<int>>& mat) {
        int n = mat[0].size();
        vector<int> dp(n + 1, 0);
        dp[1] = max(mat[0][0], mat[1][0]);
        dp[2] = max({dp[1], mat[0][1], mat[1][1]});
        
        for(int i = 3; i <= n; i++) {
            dp[i] = max({dp[i - 1], mat[0][i - 1] + dp[i - 2], mat[1][i - 1] + dp[i - 2]});
        }
        
        return dp[n];
        
    }
};
// https://leetcode.com/problems/longest-common-subsequence/

class Solution {
public:
    int res, m, n;
    vector<vector<int>> dp;
    int backtrack(int i, int j, string &text1, string &text2) {
        if(i >= m || j >= n) 
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int len = 0;
        if(text1[i] == text2[j]) {
            len = 1 + backtrack(i + 1, j + 1, text1, text2);
        }
        else {
            len = max(backtrack(i + 1, j, text1, text2), 
                    backtrack(i, j + 1, text1, text2));
        }
        dp[i][j] = len;
        return len;
    }
    int longestCommonSubsequence(string text1, string text2) {
        m = text1.size(), n = text2.size();
        dp.resize(m, vector<int>(n, -1));
        return backtrack(0, 0, text1, text2);
    }
};
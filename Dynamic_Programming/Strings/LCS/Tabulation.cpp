// https://leetcode.com/problems/longest-common-subsequence/

class Solution {
public:
    int res, m, n;
    vector<vector<int>> dp;
    int longestCommonSubsequence(string text1, string text2) {
        //   a b c d e (m)
        //  a
        //  c
        //  e
        // (n)
        
        m = text1.size(), n = text2.size();
        dp.resize(m + 1, vector<int>(n + 1, 0));

        for(int i = 1; i <= n; i++) {
            if(text1[m - 1] == text2[i - 1]) dp[m - 1][i] = 1;
        }
        for(int i = 1; i <= m; i++) {
            if(text1[i - 1] == text2[n - 1]) dp[i][n - 1] = 1;
        }

        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                int right = dp[i][j + 1];
                int down = dp[i + 1][j];
                if(text1[i] == text2[j]) dp[i][j] = 1 + dp[i + 1][j + 1];
                else dp[i][j] = max(right, down);

            }
        }
        
        // Print LCS
        string s = "";
        int i = 0, j = 0;
        while(i < m && j < m) {
            if(text1[i] == text2[j]) {
                s.push_back(text1[i]);
                i++;
                j++;
            }
            else {
                int right = dp[i][j + 1], down = dp[i + 1][j];
                if(right > down) {
                    j++;
                }
                else i++;
            }
        }
        // LCS string
        cout << s << endl;

        return dp[0][0];
    }
};
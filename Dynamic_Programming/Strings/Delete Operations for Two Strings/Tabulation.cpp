// https://leetcode.com/problems/delete-operation-for-two-strings/

class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    int minDistance(string word1, string word2) {
        m = word1.size(), n = word2.size();
        dp.resize(m + 1, vector<int>(n + 1, -1));

        for(int i = 0; i <= m; i++) {
            dp[i][n] = m - i;
        }

        for(int j = 0; j <= n; j++) {
            dp[m][j] = n - j;
        }

        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(word1[i] == word2[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                }
                else {
                    dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        return dp[0][0];
    }
};
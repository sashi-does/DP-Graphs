// https://leetcode.com/problems/shortest-common-supersequence/

class Solution {
public:
    int m, n;
    string buildLCS(string &str1, string &str2) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 0; i < m; i++) {
            dp[i][0] = 0;
        }
        for(int i = 0; i < n; i++) {
            dp[0][i] = 0;
        }
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        int i = m, j = n;
        string lcs = "";
        while(i > 0 && j > 0) {
            if(str1[i - 1] == str2[j - 1]) {
                lcs.push_back(str1[i - 1]);
                i--;
                j--;
            }
            else {
                int up = dp[i - 1][j], left = dp[i][j - 1];
                if(up < left) j--;
                else i--;
            }
        }
        reverse(lcs.begin(), lcs.end());
        return lcs;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        m = str1.size(), n = str2.size();

        string lcs = buildLCS(str1, str2);
        string scs = "";
        int i = 0, j = 0;
        for(char c : lcs) {
            while(c != str1[i]) {
                scs.push_back(str1[i]);
                i++;
            }
            while(c != str2[j]) {
                scs.push_back(str2[j]);
                j++;
            }
            scs.push_back(c);
            i++;
            j++;
        }
        while(i < m) {
            scs.push_back(str1[i]);
            i++;
        }
        while(j < n) {
            scs.push_back(str2[j]);
            j++;
        }
        return scs;
    }
};
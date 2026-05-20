// https://leetcode.com/problems/palindrome-partitioning-ii/

class Solution {
public:
    vector<int> dp;
    bool isPalindrome(string& s, int i, int j) {
        while(i < j) {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    int minCut(string s) {
        int n = s.size();
        dp.resize(n + 1, 0);
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        for(int i = n - 1; i >= 0; i--) {
            for(int j = i; j < n; j++) {
                if(s[i] == s[j] && (j - i <= 2 || pal[i + 1][j - 1])) {
                    pal[i][j] = true;
                }
            }
        }

        for(int i = n - 1; i >= 0; i--) {
            int cuts = INT_MAX;
            for(int j = i; j < n; j++) {
                if(pal[i][j]) {
                // if(isPalindrome(s, i, j)) {
                    cuts = min(cuts, 1 + dp[j + 1]);
                }
            }
            dp[i] = cuts;
        }

        return dp[0] - 1;
        
    }
};
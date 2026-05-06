// https://leetcode.com/problems/palindromic-substrings/

class Solution {
public:
    vector<vector<int>> dp;
    bool solve(int i, int j, string &s) {
        if(i > j)
            return true;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(s[i] == s[j])
            return dp[i][j] = solve(i + 1, j - 1, s);
        return dp[i][j] = false;
    }
    int countSubstrings(string s) {
        int count = 0, n = s.size();
        dp.resize(n, vector<int>(n, -1));
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(solve(i, j, s)) count++;
            }
        }
        return count;
    }
};
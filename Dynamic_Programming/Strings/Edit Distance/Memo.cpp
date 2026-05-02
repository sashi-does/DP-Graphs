// https://leetcode.com/problems/edit-distance/

class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    int backtrack(string& word1, string& word2, int i, int j) {
        if(i >= m && j >= n)
            return 0;
        if(i >= m) {
            return n - j; // insertions
        }
        if(j >= n) {
            return m - i; // deletions
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        int insert = INT_MAX, remove = INT_MAX, replace = INT_MAX;
        if(word1[i] == word2[j]) {
            return dp[i][j] = backtrack(word1, word2, i + 1, j + 1);
        }
        else {
            replace = 1 + backtrack(word1, word2, i+ 1, j + 1);
            insert = 1 + backtrack(word1, word2, i, j + 1);
            remove = 1 + backtrack(word1, word2, i + 1, j);
        }
        return dp[i][j] = min({insert, remove, replace});
    }
    int minDistance(string word1, string word2) {
        m = word1.size(), n = word2.size();
        dp.resize(m, vector<int>(n, -1));
        return backtrack(word1, word2, 0, 0);

    }
};
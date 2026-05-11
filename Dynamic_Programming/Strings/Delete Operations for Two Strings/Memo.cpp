// https://leetcode.com/problems/delete-operation-for-two-strings/

class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    int backtrack(string& word1, string& word2, int i, int j) {
        if(i == word1.size() && j == word2.size())
            return 0;

        if(i == word1.size()) 
            return word2.size() - j;
        
        if(j == word2.size()) 
            return word1.size() - i;
        
        if(word1[i] == word2[j]) 
            return dp[i][j] = backtrack(word1, word2, i + 1, j + 1);
        
        if(dp[i][j] != -1)
            return dp[i][j];

        int deleteInWord1 = 1 + backtrack(word1, word2, i + 1, j);
        int deleteInWord2 = 1 + backtrack(word1, word2, i, j + 1);

        return dp[i][j] = min(deleteInWord1, deleteInWord2);
    }
    int minDistance(string word1, string word2) {
        m = word1.size(), n = word2.size();
        dp.resize(m, vector<int>(n, -1));
        return backtrack(word1, word2, 0, 0);
    }
};
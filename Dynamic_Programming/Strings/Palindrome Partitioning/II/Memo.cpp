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
    int backtrack(string& s, int idx) {
        if(idx >= s.size()) 
            return 0;
        if(dp[idx] != -1)
            return dp[idx];
        int cuts = INT_MAX;
        for(int i = idx; i < s.size(); i++) {
            if(isPalindrome(s, idx, i)) {
                cuts = min(cuts, 1 + backtrack(s, i + 1));
            }
        }
        return dp[idx] = cuts;
    }
    int minCut(string s) {
        dp.resize(s.size(), -1);
        return backtrack(s, 0) - 1;
    }
};
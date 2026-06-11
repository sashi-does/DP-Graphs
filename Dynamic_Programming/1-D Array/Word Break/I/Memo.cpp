// https://leetcode.com/problems/word-break/description/

class Solution {
public:
    int n;
    vector<int> dp;
    bool helper(string &s, vector<string>& wordDict, int i) {
        if(i >= s.size())
            return true;
        if(dp[i] != -1)
            return dp[i];
        for(int idx = 0; idx < wordDict.size(); idx++) {
            int st = i, n = wordDict[idx].size(), p1 = 0;
            while(p1 < n && st < s.size()) {
                if(wordDict[idx][p1] != s[st]) break;
                st++;
                p1++;
            }
            if(p1 == n) {
                if(helper(s, wordDict, st)) 
                    return dp[i] = true;
            }
        }
        return dp[i] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        dp.resize(n, -1);
        return helper(s, wordDict, 0); 
    }
};
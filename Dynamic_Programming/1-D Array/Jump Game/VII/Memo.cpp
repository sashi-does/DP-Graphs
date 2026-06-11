class Solution {
public:
    int n;
    vector<int> dp;
    bool solve(int i, string &s, int minJump, int maxJump) {
        if(i == n - 1)
            return true;
            
        if(i >= n)
            return false;

        if(dp[i] != -1)
            return dp[i];

        for(int j = i + minJump; j <= min(i + maxJump, n - 1); j++) {
           
            if(s[j] == '0' && solve(j, s, minJump, maxJump)) {
                return dp[i] = true;
            }
        }

        return dp[i] = false;
    }
    bool canReach(string s, int minJump, int maxJump) {
        n = s.size();
        if(s[n - 1] != '0')
            return false;
        dp.resize(n, -1);
        dp[n - 1] = true;

        return solve(0, s, minJump, maxJump); 
    }
};
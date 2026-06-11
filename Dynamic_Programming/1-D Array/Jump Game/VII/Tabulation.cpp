class Solution {
public:
    int n;
    vector<int> dp;
    bool canReach(string s, int minJump, int maxJump) {
        n = s.size();
        if(s[n - 1] != '0')
            return false;
        dp.resize(n, -1);
        dp[n - 1] = true;

        for(int i = n - 2; i >= 0; i--) {
            dp[i] = false;
            for(int j = i + minJump; j <= min(i + maxJump, n - 1); j++) {
                if(s[j] == '0' && dp[j] == 1) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[0] == 1 ? true : false;
    }
};
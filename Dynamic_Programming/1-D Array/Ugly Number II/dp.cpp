class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        int i2 =  1, i3 = 1, i5 = 1;
        for(int i = 2; i <= n; i++) {
            int next = min({dp[i2]*2, dp[i3]*3, dp[i5]*5});
            dp[i] = next;
            if(next == dp[i2]*2) i2++;
            if(next == dp[i3]*3) i3++;
            if(next == dp[i5]*5) i5++;
        }

        return dp[n];
    }
};
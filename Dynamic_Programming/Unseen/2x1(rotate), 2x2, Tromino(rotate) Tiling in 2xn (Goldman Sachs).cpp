/*
Author: sashi-does
date: 20 july, 2026

"A year from now, you'll wish you had started today."
*/

// number of unique ways to fill 2xn with the tiles dominoes of 1x2, 2x1, 2x2 and a tromino

#include <bits/stdc++.h>
using namespace std;

signed main() {

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<vector<int>> dp(n + 1, vector<int>(3, 0));

        dp[1][0] = 1;
        dp[1][1] = 0;
        dp[1][2] = 0;


        dp[2][0] = 3;
        dp[2][1] = 1;
        dp[2][2] = 1;

      

        
        for(int i = 3; i <= n; i++) {
            // full
            dp[i][0] = dp[i - 1][2] + dp[i - 1][1] + 2 * dp[i - 2][0] + dp[i - 1][0];
            // up
            dp[i][1] = dp[i - 2][0] + dp[i - 1][2];
            // down
            dp[i][2] = dp[i - 2][0] + dp[i - 1][1];
        }

        cout << dp[n][0] << endl;
    }

    return 0;
}
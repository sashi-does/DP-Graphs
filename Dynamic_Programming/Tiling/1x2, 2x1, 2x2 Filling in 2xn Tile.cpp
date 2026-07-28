/*
Author: sashi-does
date: 20 july, 2026

"A year from now, you'll wish you had started today."
*/

// number of unique ways to fill 2xn with the tiles 1x2, 2x1, 2x2
// R.R (two relations)
// 1. dp[i] = dp[i - 1] + 2 * dp[i - 2];
// 2. dp[i] = 2 * dp[i - 1] + ((i % 2 == 0 ? 1 : -1));

#include <bits/stdc++.h>
using namespace std;

signed main() {

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        // dp[1] = 1;
        // dp[2] = 3;
        // dp[3] = 5; 2*dp[2] - 1
        // dp[4] = 11; 2*dp[3] + 1
        // dp[5] = 21; 2*dp[4] - 1

        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 3;
        for(int i = 3; i <= n; i++) {
            // alternate
            dp[i] = dp[i - 1] + 2 * dp[i - 2];

            // my approach
            // if(i % 2 == 0) 
            //     dp[i] = (dp[i - 1] * 2) + 1;
            // else
            //     dp[i] = (dp[i - 1] * 2) - 1;
        }

        cout << dp[n] << endl;
    }

    return 0;
}
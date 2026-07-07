/*
Author: sashi-does
date: 8 july, 2026

"A year from now, you'll wish you had started today."
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int items, size;
	cin >> items >> size;
	
	vector<int> w(items + 1);
	for(int i = 1; i <= items; i++) {
	    cin >> w[i];
	}
	
	vector<int> p(items + 1);
	for(int i = 1; i <= items; i++) {
	    cin >> p[i];
	}
	
    // ################# One Bag #################
    // dp[i][j] -> max profit for the first i items with capacity of j
	vector<vector<int>> dp(items + 1, vector<int>(size + 1, 0));
	for(int i = 1; i <= items; i++) {
	    for(int j = 1; j <= size; j++) {
	        int notPick = dp[i - 1][j];
	        int pick = (j - w[i] >= 0 ? p[i] + dp[i - 1][j - w[i]] : 0);
	        dp[i][j] = max(pick, notPick);
	    }
	}

	cout << "One Bag: " << dp[items][size] << endl;

    // ################# Two Bags #################
    // dp[i][j][k] -> max profit for the first i items with capacity of j of bag1 and k of bag2
	vector<vector<vector<int>>> dp(items + 1, vector<vector<int>>(size + 1, vector<int>(size + 1, 0)));
	for(int i = 1; i <= items; i++) {
        for(int j = 1; j <= size; j++) {
            for(int k = 1; k <= size; k++) {
                dp[i][j][k] = max({
                    dp[i - 1][j][k],
                    (j - w[i] >= 0 ? p[i] + dp[i - 1][j - w[i]][k] : 0),
                    (k - w[i] >= 0 ? p[i] + dp[i - 1][j][k - w[i]] : 0)
                });
            }
        }
    }
	
	cout << "Two Bags: " << dp[items][size][size] << endl;
    
	
	// ################# Three Bags #################
    // dp[i][j][k][l] -> max profit for the first i items with capacity of j size of bag1, k size of bag2 and l size of bag3
	vector<vector<vector<vector<int>>>> dp(items + 1, vector<vector<vector<int>>>(size + 1, vector<vector<int>>(size + 1, vector<int>(size + 1, 0))));
    for(int i = 1; i <= items; i++) {
        for(int j = 1; j <= size; j++) {
            for(int k = 1; k <= size; k++) {
                for(int l = 1; l <= size; l++) {
                    dp[i][j][k][l] = max({
                        dp[i - 1][j][k][l],
                        (j - w[i] >= 0 ? p[i] + dp[i - 1][j - w[i]][k][l] : 0),
                        (k - w[i] >= 0 ? p[i] + dp[i - 1][j][k - w[i]][l] : 0),
                        (l - w[i] >= 0 ? p[i] + dp[i - 1][j][k][l - w[i]] : 0)
                    });
                }
            }
        }
    }
	
	cout << dp[items][size][size][size] << endl;
}

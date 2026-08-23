/*
Author: sashi-does
date: 31 july, 2026

"A year from now, you'll wish you had started today."
*/



#include <bits/stdc++.h>
using namespace std;

// N,M<=1000 
// 1<=mn[i],mx[i]<=50 


int solve(
	vector<int>& cost, 
	vector<int>& happiness, 
	vector<int>& minQty, 
	vector<int>& maxQty, int idx, int budget, int n,
	vector<vector<int>>& dp) {
	    

		if(idx >= n) 
			return 0;
		if(budget - (minQty[idx] * cost[idx]) < 0)
			return INT_MIN;
			
		if(dp[idx][budget] != -1)
		    return dp[idx][budget];

		int minCase = solve(cost, happiness, minQty, maxQty, idx + 1, budget - (cost[idx] * minQty[idx]), n, dp);
		
		if(minCase != INT_MIN)
		    minCase = happiness[idx] * minQty[idx] + minCase;
		
		int optimal = INT_MIN;
		for(int qty = minQty[idx] + 1; qty <= maxQty[idx]; qty++) {
			if(budget - (cost[idx] * qty) < 0)
				break;
			int res = solve(cost, happiness, minQty, maxQty, idx + 1, budget - (cost[idx] * qty), n, dp);
			if(res == INT_MIN)
				continue;
			optimal = max(optimal, (happiness[idx] * qty) + res);
		}

		return dp[idx][budget] = max(minCase, optimal);

}	


signed main() {

    int t;
    cin >> t;

    while(t--) {

        int n, m;
		cin >> n >> m;

		vector<int> cost(n);
		for(int i = 0; i < n; i++)
			cin >> cost[i];
	
		vector<int> happiness(n);
		for(int i = 0; i < n; i++)
			cin >> happiness[i];
		
		vector<int> minQty(n);
		for(int i = 0; i < n; i++)
			cin >> minQty[i];
		
		vector<int> maxQty(n);
		for(int i = 0; i < n; i++)
			cin >> maxQty[i];
			
		vector<vector<int>> dp(n, vector<int>(m + 1, -1));
		int res = solve(cost, happiness, minQty, maxQty, 0, m, n, dp);
		
		cout << (res == INT_MIN ? 0 : res) << endl;
        
        
    }

    return 0;
}


/*
Author: sashi-does
date: 20 july, 2026

"A year from now, you'll wish you had started today."
*/

// https://leetcode.com/discuss/post/8409327/phonepe-oa-50lpa-ctc-2027-grad-camera-on-7to7/

#include <bits/stdc++.h>
using namespace std;

int dfs(vector<bool> &visited, int node, vector<int> &store, vector<vector<int>> &adj, vector<int> &color) {
    visited[node] = true;
    store[color[node]]++;
    int count = 1;
    for(int neigh : adj[node]) {
        if(!visited[neigh]) {
            count += dfs(visited, neigh, store, adj, color);
        }
    }
    return count;
}

signed main() {

    int t;
    cin >> t;

    while(t--) {
        // socks, days, colors
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> color(n + 1);
        for(int i = 1; i <= n; i++)
            cin >> color[i];
        
        vector<int> cost(n + 1);
        for(int i = 1; i <= k; i++)
            cin >> cost[i];
        
        vector<vector<int>> adj(n + 1);
        for(int i = 0; i < m; i++) {
            // sock number on left and right foot
            int l, r;
            cin >> l >> r;
            adj[l].push_back(r);
            adj[r].push_back(l);
        }
        
        vector<bool> visited(n + 1, false);
        int totalCost = 0;
        for(int i = 1; i <= n; i++) {
            if(!visited[i]) {
                vector<int> store(k + 1, 0);
                int sz = dfs(visited, i, store, adj, color);
                // cout << sz << endl;

                int minCost = INT_MAX;
                for(int i = 1; i <= k; i++) {
                    minCost = min((sz - store[i]) * cost[i], minCost);
                }
                
                totalCost += minCost;
            }
        }
        cout << totalCost << endl;
    }

    return 0;
}
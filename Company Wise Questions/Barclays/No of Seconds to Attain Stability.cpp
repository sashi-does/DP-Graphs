/*
Author: sashi-does
date: 1 august, 2026

"A year from now, you'll wish you had started today."
*/

// https://docs.google.com/document/d/1q7fAV3CUsF2ARmw8-2UruuZ8G6gSSdl1fUv5pcJJhcg/edit?tab=t.0


#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> T;

signed main() {

    int t;
    cin >> t;

    while (t--) {

        int n, e;
        cin >> n >> e;

        vector<vector<int>> adj(n);
        vector<int> deg(n, 0);

        for(int i = 0; i < e; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }
       

        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(deg[i] < 2)
                q.push(i);  
        }

        int clock = 0;
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                int front = q.front();
                q.pop();
                for(int neigh : adj[front]) {
                    if(deg[neigh] > 0)
                        deg[neigh]--;
                    if(deg[neigh] < 2 && deg[neigh] > 0) {
                        q.push(neigh);
                    }
                }
            }
            clock++;
        }

        cout << clock << endl;


    }

    return 0;
}
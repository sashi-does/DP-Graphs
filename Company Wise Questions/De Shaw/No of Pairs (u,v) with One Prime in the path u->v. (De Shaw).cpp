#include <stdio.h>
#include <bits/stdc++.h>
#include <vector>
#include <math.h>

using namespace std;


vector<bool> prime(101, true);
void computePrime() {
    prime[1] = false;
    for(int i = 2; i < 101; i++) {
        int idx = 2;
        while(i * idx < 101) {
            prime[i * idx] = false;
            idx++;
        }
    }
}

int main() {

    int n;
    cin >> n;

    int edges, u, v;
    cin >> edges;
    
    vector<vector<int>> adj(n + 1);
    vector<int> par(n + 1, -1);
    for(int i = 0; i < edges; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        par[v] = u;
    }

    computePrime();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    queue<int> q;
    q.push(1);

    while(!q.empty()) {
        int front = q.front();
        q.pop();
        for(int neigh : adj[front]) {
            if(dp[front][neigh] == -1) {
                dp[front][neigh] = (par[neigh] != -1 ? dp[front][par[neigh]] : 0) + (prime[front] + prime[neigh]);
                q.push(neigh);
            }
        }
    }

    int pairs = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i < j) {
                if(dp[i][j] == 1)
                    pairs++;
            }
        }
    }

    cout << pairs << endl;

    return 0;
}

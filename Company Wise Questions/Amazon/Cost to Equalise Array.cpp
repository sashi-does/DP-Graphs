/*
Author: sashi-does
date: 1 august, 2026

"A year from now, you'll wish you had started today."
*/

// https://docs.google.com/document/d/1RPTRX6_jbEwgxrs2yIVaCo_oRLweF7sdlTRZWco0pvM/edit?tab=t.0



#include <bits/stdc++.h>
using namespace std;

signed main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> nums(n);
        unordered_map<int, int> tot;
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
            tot[nums[i]]++;
        }

        if((int)tot.size() == 1) {
            cout << 0 << endl;
            continue;
        }
        
        int minCost = INT_MAX;
        unordered_map<int, int> track;

        for(int i = 0; i < n; i++) {
            int total = tot[nums[i]];
            int lcnt = track[nums[i]];
            int rcnt = total - lcnt - 1;
            int left = 0, right = 0;

            if(lcnt != i) {
                left = (i * nums[i]);
            }
            
            if(rcnt != n - i - 1) {
                right = (n - i - 1) * nums[i];
            }

            minCost = min(minCost, left + right);

            track[nums[i]]++;
        }

        cout << minCost << endl;

    }

    return 0;
}
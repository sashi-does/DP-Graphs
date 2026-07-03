// https://atcoder.jp/contests/dp/tasks/dp_c 

#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin >> n;
	vector<int> a(n + 1), b(n + 1), c(n + 1);
	vector<int> dpa(n + 1), dpb(n + 1), dpc(n + 1);
	for(int i = 0; i < n; i++) {
	    int aa, bb, cc;
	    cin >> aa >> bb >> cc;
	    a[i + 1] = aa;
	    b[i + 1] = bb;
	    c[i + 1] = cc;
	}
	
    dpa[1] = a[1];
    dpb[1] = b[1];
    dpc[1] = c[1];
    
    for(int i = 2; i <= n; i++) {
        dpa[i] = a[i] + max(dpb[i - 1], dpc[i - 1]);
        dpb[i] = b[i] + max(dpa[i - 1], dpc[i - 1]);
        dpc[i] = c[i] + max(dpa[i - 1], dpb[i - 1]);
    }
    
    cout << max({dpa[n], dpb[n], dpc[n]}) << endl;

}

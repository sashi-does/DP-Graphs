// https://www.desiqna.in/10567/barclays-sde-coding-oa-questions-and-solutions-set-8-2022-dp

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> easy(n + 1);
	vector<int> hard(n + 1);
	int x, y;
	for(int i = 1; i <= n; i++) {
	    cin >> x >> y;
	    easy[i] = x;
	    hard[i] = y;
	}
	
	vector<int> dpe(n + 1, 0);
	vector<int> dph(n + 1, 0);
	
	
	// first day has no previous day so we are free to do any task
	dpe[1] = max(easy[1], hard[1]);
	dph[1] = max(easy[1], hard[1]);
	
    // 	dpe[2] = max(dpe[1] + easy[2], dpe[2 - 2] + hard[2]);
    // 	dph[2] = max(hard[2] + dph[2 - 2], dpe[2]);
	
	
	for(int i = 2; i <= n; i++) {
	    dpe[i] = max(dpe[i - 1] + easy[i], hard[i] + dpe[i - 2]);
	    dph[i] = max(dph[i - 2] + hard[i], dpe[i]);
	}

    cout << max(dpe[n], dph[n]) << endl;
}

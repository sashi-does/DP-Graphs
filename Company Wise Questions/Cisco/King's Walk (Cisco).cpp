// https://www.desiqna.in/11291/cisco-coding-solutions-2023-dynamic-programming-kings-walk

#include <bits/stdc++.h>
using namespace std;

int main() {
	int m, n;
	cin >> m >> n;
	
	vector<vector<int>> board(m + 1, vector<int>(n + 1, 0));

	for(int i = 1; i <= m; i++) {
	    for(int j = 1; j <= n; j++) {
	        if(i == 1 && j == 1)
	            board[i][j] = 1;
	        else
	            board[i][j] = board[i - 1][j] + board[i][j - 1] + board[i - 1][j - 1];
	    }
	}
	
	cout << board[m][n] << endl;

}

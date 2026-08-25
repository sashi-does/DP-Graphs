/*
Author: sashi-does
date: 25 august, 2026

"A year from now, you'll wish you had started today."
*/

// https://docs.google.com/document/d/1vPiPTdy9CnO7PeXO6DDGz1zrEu4Con90gFnJCTbmuRA/edit?tab=t.0


#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> T;

static vector<int> dx = {-1, 1, 0, 0};
static vector<int> dy = {0, 0, -1, 1};

bool isValid(int x, int y, int m, int n) {
    return (x >= 0 && x < m && y >= 0 && y < n);
}

signed main() {

    int t;
    cin >> t;

    while (t--) {

        int m, n;
        cin >> m >> n;

        vector<vector<char>> grid(m, vector<char>(n));
        queue<T> q;
        int dst = 0, src = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                cin >> grid[i][j];
                if(grid[i][j] == 'S') {
                    q.push({i, j});
                    visited[i][j] = true;
                }
                else if(grid[i][j] == 'T')
                    dst++;
            }
        }
        
        int clock = 1, time = -1;

        while(!q.empty()) {
            // cout << "sashi";
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                T front = q.front();
                q.pop();
                int cx = front.first, cy = front.second;
                // cout << "________\n";
                for(int i = 0; i < 4; i++) {
                    int x = cx + dx[i], y = cy + dy[i];
                    // cout << x << " " << y << endl;
                    if(!isValid(x, y, m, n))
                        continue;
                    if(visited[x][y])
                        continue;
                    visited[x][y] = true;
                    if(grid[x][y] == 'T') {
                        dst--;
                        time = clock;
                    }
                    else if(grid[x][y] != 'B') {
                        q.push({x, y});
                    }
                }
                if(dst == 0) {
                    break;
                }
            }
            if(dst == 0) {
                break;
            }
            clock++;
        }

        cout << (dst == 0 ? time : -1) <<  endl;

    }

    return 0;
}
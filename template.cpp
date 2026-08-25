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
static vector<int> dy = {0, 0, -1, 0};

signed main() {

    int t;
    cin >> t;

    while (t--) {

        int m, n;
        cin >> m >> n;

        vector<vector<int>> grid(m, vector<int>(n));
        queue<T> q;
        int dst = 0, src = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                cin >> grid[i][j];
                if(grid[i][j] == 'S') {
                    src++;
                    q.push({i, j});
                }
                else if(grid[i][j] == 'T')
                    dst++;
            }
        }
        
        int clock = 0, time = 0;
        vector<vector<bool>> visited(m, vector<int>(n, false));

        while(!q.empty()) {
            T front = q.front();
            int cx = front.first, cy = front.second;
            for(int i = 0; i < 4; i++) {
                int x = cx + dx[i], y = cy + dy[i];
                if(!isValid(x, y))
                    continue;
                if(visited[x][y])
                    continue;
                if(grid[x][y] == 'T') {
                    dst--;
                    if(dst == 0) {
                        time = clock;
                        break;
                    }
                }
                if(grid[x][y] != 'B') {
                    q.push({x, y});
                }
            }
            clock++;
        }

        cout << time << endl;

    }

    return 0;
}
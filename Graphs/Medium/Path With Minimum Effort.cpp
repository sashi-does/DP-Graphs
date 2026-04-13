// https://leetcode.com/problems/path-with-minimum-effort/

typedef pair<int, pair<int, int>> T;
class Solution {
public:
    int m, n;
    vector<int> xc = {1, 0, -1, 0};
    vector<int> yc = {0, 1, 0, -1};
    bool isValid(int x, int y, vector<vector<int>>& heights) {
        return ((x >= 0 && x < m) && (y >= 0 && y < n) && heights[x][y] != -1);
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<T, vector<T>, greater<T>> pq;
        int wt, x, y;
        m = heights.size(), n = heights[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        while(!pq.empty()) {
            T front = pq.top();
            pq.pop();
            auto [curr_x, curr_y] = front.second;
            wt = front.first;
            for(int i = 0; i < 4; i++) {
                x = xc[i] + curr_x, y = yc[i] + curr_y;
                if(isValid(x, y, heights)) {
                    if(dist[x][y] > max(wt, abs(heights[x][y] - heights[curr_x][curr_y]))) {
                        dist[x][y] = max(wt, abs(heights[x][y] - heights[curr_x][curr_y]));
                        pq.push({dist[x][y], {x, y}});
                    }
                }
            }
        }
        return dist[m - 1][n - 1] == INT_MAX ? -1 : dist[m - 1][n - 1];
    }
};
// https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        int v = dist.size(), n = dist[0].size();
        for(int via = 0; via < v; via++) {
            for(int i = 0; i < v; i++) {
                for(int j = 0; j < n; j++) {
                    int srcToVia = dist[i][via];
                    int viaToDest = dist[via][j];
                    if(srcToVia + viaToDest < dist[i][j]) {
                        dist[i][j] = srcToVia + viaToDest;
                    }
                }
            }
        }

        // negative cycle detection
        for(int i = 0; i < n; i++) {
            if(dist[i][i] < 0)
                cout << "Cycle Present\n";
        }
        
    }
};
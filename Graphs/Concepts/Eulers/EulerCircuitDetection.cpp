// https://www.geeksforgeeks.org/problems/euler-circuit-in-a-directed-graph/1

class Solution {
  public:
    bool isEularCircuitExist(int v, vector<int> adj[]) {
        vector<int> inDeg(v, 0);
        for(int i = 0; i < v; i++) {
            for(int node : adj[i]) {
                inDeg[node]++;
            }
        }
        for(auto &n : inDeg) {
            if(n % 2 != 0)
                return false;
        }
        return true;
        
    }
};
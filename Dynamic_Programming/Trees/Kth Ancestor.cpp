// https://leetcode.com/problems/kth-ancestor-of-a-tree-node/

class TreeAncestor {
private:
    int dfs(int node, int k, int cnt) {
        if(k <= 0)
            return node;
        if(node == -1)
            return -1;

        if(cnt >= dp[0].size())
            return -1;

        int bit = k & 1;
        
        if(bit == 1) {
            node = dp[node][cnt];
        }
        return dfs(node, k >> 1, cnt + 1);

    }
    void populate(vector<int>& parent, int n) {
        int log = ceil(log2(n)) + 1;
        dp.resize(n, vector<int>(log, -1));
        for(int i = 0; i < n; i++) 
            dp[i][0] = parent[i];
            for(int j = 1; j < log; j++) {
                for(int i = 0; i < n; i++) {
                    if(dp[i][j - 1] != -1)
                        dp[i][j] = dp[dp[i][j - 1]][j - 1];
            }
        }
    }
public:
    vector<vector<int>> dp;
    int n;
    TreeAncestor(int n, vector<int>& parent) {
        this->n = n;
        this->populate(parent, n);
    }
    
    int getKthAncestor(int node, int k) {
        return dfs(node, k, 0);
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
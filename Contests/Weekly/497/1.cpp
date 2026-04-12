// https://leetcode.com/problems/find-the-degree-of-each-vertex/description/

class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int> deg(matrix.size(), 0);
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix.size(); j++) {
                if(matrix[i][j])
                    deg[i]++;
            }
        }
        return deg;
    }
};
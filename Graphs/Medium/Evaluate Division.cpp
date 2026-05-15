// https://leetcode.com/problems/evaluate-division/description/

class Solution {
public:
    unordered_map<string, vector<pair<float, string>>> store;

    double backtrack(unordered_set<string>& visited, string src, string dest) {
        if(src == dest)
            return 1.0;

        for(auto &it : store[src]) {
            if(visited.find(it.second) == visited.end()) {
                visited.insert(it.second);
                double res = backtrack(visited, it.second, dest);
                if(res != -1.0) {
                    return it.first * res;
                }
                visited.erase(it.second);
            }
        }

        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        int idx = 0;
        for(auto &eq : equations) {
            store[eq[0]].push_back({values[idx], eq[1]});
            store[eq[1]].push_back({1/values[idx], eq[0]});
            idx++;
        }

        vector<double> res;
        unordered_set<string> visited;
        for(auto &q : queries) {
            if(store.find(q[0]) == store.end())
                res.push_back(-1);
            else {
                visited.clear();
                res.push_back(backtrack(visited, q[0], q[1]));
            }
        }

        return res;
    }
};


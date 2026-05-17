// https://leetcode.com/problems/jump-game-iii/description/

class Solution {
public:
    unordered_set<int> seen;
    bool backtrack(vector<int>& arr, int idx) {
        if(idx < 0 || idx >= arr.size()) 
            return false;
        if(arr[idx] == 0) 
            return true;
        if(seen.find(idx) != seen.end())
            return false;
        seen.insert(idx);
        if(backtrack(arr, idx + arr[idx]))
            return true;
        bool res = backtrack(arr, idx - arr[idx]);
        seen.erase(idx);
        return res;
    }
    bool canReach(vector<int>& arr, int start) {
        return backtrack(arr, start);
    }
};
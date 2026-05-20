// https://leetcode.com/problems/palindrome-partitioning/

class Solution {
public:
    vector<vector<string>> store;
    bool isPalindrome(int i, int j, string& s) {
        while(i < j) {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void backtrack(string &s, int idx, vector<string> &temp) {
        if(idx >= s.size()) {
            store.push_back(temp);
            return;
        }
        for(int i = idx; i < s.size(); i++) {
            if(isPalindrome(idx, i, s)) {
                temp.push_back(s.substr(idx, i - idx + 1));
                backtrack(s, i + 1, temp);
                temp.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        backtrack(s, 0, temp);
        return store;
    }
};
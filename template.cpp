/*
Author: sashi-does
date: 1 august, 2026

"A year from now, you'll wish you had started today."
*/

// https://leetcode.com/discuss/post/8439839/google-swe-intern-interview-experience-r-vi40/



#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    int leftWt, rightWt;

    Node(int x) {
        val = x;
        left = right = nullptr;
        leftWt = rightWt = 0;
    }
};

int minWeightToRemoveLeaves(Node* root) {
    if(!root)
        return 0;
    if(!root->left && !root->right)
        return INT_MAX;

    int leftMin = minWeightToRemoveLeaves(root->left);
    int rightMin = minWeightToRemoveLeaves(root->right);

    return min(leftMin, root->leftWt) + min(rightMin, root->rightWt);
}




signed main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        unordered_map<int, Node*> mp;
        unordered_set<int> child;

        for (int i = 0; i < n - 1; i++) {

            int parent, curr, wt;
            char dir;
            cin >> parent >> curr >> dir >> wt;

            if (!mp.count(parent))
                mp[parent] = new Node(parent);

            if (!mp.count(curr))
                mp[curr] = new Node(curr);

            if (dir == 'L') {
                mp[parent]->left = mp[curr];
                mp[parent]->leftWt = wt;
            }
            else {
                mp[parent]->right = mp[curr];
                mp[parent]->rightWt = wt;
            }

            child.insert(curr);
        }

        Node* root = nullptr;

        for (auto &[val, node] : mp) {
            if (!child.count(val)) {
                root = node;
                break;
            }
        }

        cout << minWeightToRemoveLeaves(root) << endl;

    }

    return 0;
}
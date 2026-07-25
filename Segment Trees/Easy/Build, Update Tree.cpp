/*
Author: sashi-does
date: 20 july, 2026

"A year from now, you'll wish you had started today."
*/

#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    int constructTree(int l, int h, int idx) {
        if(l == h) {
            seg[idx] = arr[l];
            return seg[idx];
        }
        int mid = l + (h - l) / 2;
        int left = this->constructTree(l, mid, 2 * idx + 1);
        int right = this->constructTree(mid + 1, h, 2 * idx + 2);
        return seg[idx] = left + right;
    }
    int modifyTree(int l, int h, int idx, int pos, int val) {

        if(l == h) {
            arr[pos] = val;
            seg[idx] = val;
            return seg[idx];
        }

        int mid = l + (h - l) / 2;
        int left = (pos <= mid ? modifyTree(l, mid, 2 * idx + 1, pos, val) : seg[2 * idx + 1]);
        int right = (pos > mid ? modifyTree(mid + 1, h, 2 * idx + 2, pos, val) : seg[2 * idx + 2]);

        return seg[idx] = left + right;
    }
public:
    int n;
    vector<int> arr;
    vector<int> seg;
    SegmentTree(vector<int>& arr) {
        this->arr = arr;
        n = arr.size();
        seg.resize(4 * n, -1);
    }
    
    void buildTree() {
        this->constructTree(0, n - 1, 0);
    }

    void updateTree(int idx, int val) {
        this->modifyTree(0, n - 1, 0, idx, val);
    }

    void printTree() {
        for(int val : this->seg) {
            if(val == -1) break;
            cout << val << " ";
        }
        cout << endl;
    }

};

int main() {
    vector<int> arr = {1, 2, 3, 4};
	SegmentTree sg(arr);

	sg.buildTree();
    sg.printTree();
    
    // replace the number at given index
    // {idx, val}
    vector<vector<int>> queries = {{3, 10}, {2, 5}};
    for(auto &q : queries) {
        sg.updateTree(q[0], q[1]);
        sg.printTree();
    }

}

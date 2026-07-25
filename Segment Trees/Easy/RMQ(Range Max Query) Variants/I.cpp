/*
Author: sashi-does
date: 20 july, 2026

"A year from now, you'll wish you had started today."
*/

//  RMQ Variant - 1
// will be given q queries (each query[i] has a range {x, y})
// q[i] = {x, y} 
// have to find the max element to the right side of the range {x, y} i.e {y + 1, n - 1}

#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    int getMaxIdx(int l, int r, int tl, int tr, int idx) {
        if(r < tl || l > tr)
            return -1;
        if(l >= tl && r <= tr)
            return seg[idx];

        int mid = l + (r - l) / 2;
        int leftMinIdx = getMaxIdx(l, mid, tl, tr, 2 * idx + 1);
        int rightMinIdx = getMaxIdx(mid + 1, r, tl, tr, 2 * idx + 2);
        
        if(leftMinIdx == -1)
            return rightMinIdx;
        if(arr[leftMinIdx] > arr[rightMinIdx]) 
            return leftMinIdx;
        return rightMinIdx;
    }
public:
    int n;
    vector<int> arr;
    vector<int> seg;
    int buildTree(int l, int r, int idx) {
        if(l == r) {
            seg[idx] = l;
            return l;
        }
        int mid = l + (r - l) / 2;
        int leftMinIdx = buildTree(l, mid, 2 * idx + 1);
        int rightMinIdx = buildTree(mid + 1, r, 2 * idx + 2);
        if(arr[leftMinIdx] > arr[rightMinIdx]) 
            seg[idx] = leftMinIdx;
        else 
            seg[idx] = rightMinIdx;
        return seg[idx];
    }
    SegmentTree(vector<int> &arr, int n) {
        this->n = n;
        this->arr = arr;
        seg.resize(4 * n);
        buildTree(0, n - 1, 0);
    }
    int maxIdxAfterRange(int l, int r) {
        return getMaxIdx(0, n - 1, r + 1, n - 1, 0);
    }
    void printSegTree() {
        for(int node : seg)
            cout << node << " ";
        cout << endl;
    }
};

signed main() {

    int t;
    cin >> t;
    
    while(t--) {
        
        int n, q;
        cin >> n >> q;
        
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        
        SegmentTree sg(arr, n);
        // sg.printSegTree();
        for(int i = 0; i < q; i++) {
            int x, y;
            cin >> x >> y; 
            cout << sg.maxIdxAfterRange(x, y) << endl;
        }
        
        cout << endl;
    }

    return 0;
}
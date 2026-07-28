/*
Author: sashi-does
date: 26 july, 2026

"A year from now, you'll wish you had started today."
*/

//  RMQ Variant - 2
// will be given q queries (each query[i] has a range {x, y})
// q[i] = {x, y} 
// have to find the any element (index precisely : idx) on the right side (y + 1, n - 1) of range such that 
// arr[idx] > arr[x] && arr[idx] > arr[y]

#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    int getMaxOfXY(int l, int r, int tl, int tr, int idx) {
        if(r < tl || l > tr)
            return -1;
        if(l >= tl && r <= tr)
            return seg[idx];

        int mid = l + (r - l) / 2;
        int leftIdx = getMaxOfXY(l, mid, tl, tr, 2 * idx + 1);
        int rightIdx = getMaxOfXY(mid + 1, r, tl, tr, 2 * idx + 2);
        if(leftIdx != -1 && arr[leftIdx] > arr[x] && arr[leftIdx] > arr[y])
            return leftIdx;
        if(rightIdx != -1 && arr[rightIdx] > arr[x] && arr[rightIdx] > arr[y])
            return rightIdx;
        return -1;
    }
    int buildTree(int l, int r, int idx) {
        if(l == r) {
            seg[idx] = l;
            return l;
        }
        int mid = l + (r - l) / 2;
        int leftMaxIdx = buildTree(l, mid, 2 * idx + 1);
        int rightMaxIdx = buildTree(mid + 1, r, 2 * idx + 2);
        if(arr[leftMaxIdx] < arr[rightMaxIdx]) {
            seg[idx] = rightMaxIdx;
            return rightMaxIdx;
        }
        seg[idx] = leftMaxIdx;
        return leftMaxIdx;
    }
public:
    int n, x, y;
    vector<int> arr;
    vector<int> seg;
    SegmentTree(int n, vector<int> &arr) {
        this->n = n;
        this->arr = arr;
        seg.resize(4 * n);
        buildTree(0, n - 1, 0);
    }
    int query(int x, int y) {
        this->x = x;
        this->y = y;
        return getMaxOfXY(0, n - 1, y + 1, n - 1, 0);
    }
    void printTree() {
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
        
        SegmentTree sg(n, arr);
        // sg.printTree();
        for(int i = 0; i < q; i++) {
            int x, y;
            cin >> x >> y; 
            cout << sg.query(x, y) << endl;
        }
        
        cout << endl;
    }

    return 0;
}
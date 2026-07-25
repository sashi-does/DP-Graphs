// https://www.geeksforgeeks.org/problems/range-min-max-queries4557/1

class Solution {
  public:
    // Returns a vector<int> of size 2 where:
    // [0] = minimum value in arr from index L to R (inclusive),
    // [1] = maximum value in arr from index L to R (inclusive).
    // Uses the prebuilt segTree where each node stores [min, max].
    // Segment tree indexing:
    // - For a node at idx, left child is at 2*idx + 1, right child at 2*idx + 2.
    int n;
    vector<int> getRes(vector<int>& arr, int l, int r, int L, int R, 
                vector<vector<int>>& segTree, int idx) {
        if(r < L || l > R)
            return {INT_MAX, INT_MIN};
        if(l >= L && r <= R)
            return {segTree[idx][0], segTree[idx][1]};
        int mid = l + (r - l) / 2;
        vector<int> left = getRes(arr, l, mid, L, R, segTree, 2 * idx + 1);
        vector<int> right = getRes(arr, mid + 1, r, L, R, segTree, 2 * idx + 2);
        return {min(left[0], right[0]), max(left[1], right[1])};
    }
        
    vector<int> modify(int l, int r, int idx, int tarIdx, int tar, 
                vector<vector<int>>& segTree) {
        if(l == r) {
            segTree[idx][0] = tar;
            segTree[idx][1] = tar;
            return {tar, tar};
        }
        int mid = l + (r - l) /2 ;
        vector<int> left = {segTree[2 * idx + 1][0], segTree[2 * idx + 1][1]};
        vector<int> right = {segTree[2 * idx + 2][0], segTree[2 * idx + 2][1]};
        if(tarIdx <= mid) {
            left = modify(l, mid, 2 * idx + 1, tarIdx, tar, segTree);
        }
        else {
            right = modify(mid + 1, r, 2 * idx + 2, tarIdx, tar, segTree);
        }
        segTree[idx][0] = min(left[0], right[0]);
        segTree[idx][1] = max(left[1], right[1]);
        return {segTree[idx][0], segTree[idx][1]};
    }
    
    vector<int> getMinMax(vector<int>& arr, int L, int R,
                          vector<vector<int>>& segTree) {
        // code here
        n = arr.size();
        return getRes(arr, 0, n - 1, L, R, segTree, 0);
    }

    // Updates the value at arr[index] to 'value' and updates the segTree accordingly.
    // Uses the prebuilt segTree where each node stores [min, max].
    // Segment tree indexing:
    // - For a node at idx, left child is at 2*idx + 1, right child at 2*idx + 2.
    void updateValue(vector<int>& arr, int index, int value,
                     vector<vector<int>>& segTree) {
        n = arr.size();
        arr[index] = value;
        modify(0, n - 1, 0, index, value, segTree);
        
    }
};
// https://leetcode.com/problems/range-sum-query-mutable/description/

class SegmentTree {
private:
    int compute_sum(int l, int r, int tl, int tr, int idx) {
        if(r < tl || l > tr) 
            return 0;
        if(l >= tl && r <= tr)
            return this->seg[idx];
        int mid = l + (r - l) / 2; 
        return (compute_sum(l, mid, tl, tr, 2 * idx + 1) +
                     compute_sum(mid + 1, r, tl, tr, 2 * idx + 2));
    }
    int modify_tree(int l, int r, int tarIdx, int tar, int idx) {
        if(l == r) {
            return this->seg[idx] = tar;
        }
        int mid = l + (r - l) / 2;
        int left = this->seg[2 * idx + 1], right = this->seg[2 * idx + 2];
        if(tarIdx <= mid) {
            left = modify_tree(l, mid, tarIdx, tar, 2 * idx + 1);
        }
        else {
            right = modify_tree(mid + 1, r, tarIdx, tar, 2 * idx + 2);
        }
        return this->seg[idx] = left + right;
    }
public: 
    int n;
    vector<int> nums;
    vector<int> seg;
    int getSum(int tl, int tr) {
        return this->compute_sum(0, n - 1, tl, tr, 0);
    }
    void update(int idx, int val) {
        this->modify_tree(0, n - 1, idx, val, 0);
    }
    int buildTree(int l, int r, int idx) {
        if(l == r)
            return this->seg[idx] = this->nums[l];
        int mid = l + (r - l) / 2;
        return this->seg[idx] = (
            buildTree(l, mid, 2 * idx + 1) + 
            buildTree(mid + 1, r, 2 * idx + 2)
        );

    }
    SegmentTree(vector<int> nums, int n) {
        this->n = n;
        seg.resize(4 * n, 0);
        this->nums.resize(n);
        for(int i = 0; i < n; i++)
            this->nums[i] = nums[i];
        this->buildTree(0, n - 1, 0);
    }
};

class NumArray {
public:
    SegmentTree* sg;
    NumArray(vector<int>& nums) {
        this->sg = new SegmentTree(nums, (int) nums.size());
    }
    
    void update(int index, int val) {
        sg->update(index, val);
    }
    
    int sumRange(int left, int right) {
        return sg->getSum(left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
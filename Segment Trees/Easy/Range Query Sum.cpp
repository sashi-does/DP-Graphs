// https://leetcode.com/problems/range-sum-query-immutable/description/

class SegmentTree {
private:
    int query(int st, int en, int l, int h, int idx) {
        // range is outof interval
        if(h < st || l > en)
            return 0;
        // range is inside interval
        if(st <= l && en >= h) 
            return seg[idx];
        // range is overlapping 
        int mid = l + (h - l) / 2;
        int left = query(st, en, l, mid, 2 * idx + 1);
        int right = query(st, en, mid + 1, h, 2 * idx + 2);
        return left + right;
    }
public:
    int n;
    vector<int> seg;
    void buildTree(vector<int> &nums, int l, int h, int idx) {
        if(l == h) {
            seg[idx] = nums[l];
            return;
        }
        int mid = l + (h - l) / 2;
        buildTree(nums, l, mid, 2 * idx + 1);
        buildTree(nums, mid + 1, h, 2 * idx + 2);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
        return;
    }
    SegmentTree(vector<int>& nums) {
        n = nums.size();
        seg.resize(4 * n, -1);
        this->buildTree(nums, 0, n - 1, 0);
    }
    int querySum(int left, int right) {
        return this->query(left, right, 0, n - 1 , 0);
    }
    void printTree() {
        for(int node : seg) {
            if(node == -1) break;
            cout << node << " ";
        }
        cout << endl;
    }
};


class NumArray {
public:
    SegmentTree* sg;
    
    NumArray(vector<int>& nums) {
        sg = new SegmentTree(nums);
        // sg->printTree();
    }
    
    int sumRange(int left, int right) {
        return sg->querySum(left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
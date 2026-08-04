// https://leetcode.com/problems/find-building-where-alice-and-bob-can-meet/

class SegmentTree {
private:
    int build(int l, int r, int idx) {
        if(l == r) {
            seg[idx] = l;
            return l;
        }
        int mid = l + (r - l) / 2;
        int left = build(l, mid, 2 * idx + 1);
        int right = build(mid + 1, r, 2 * idx + 2);

        if(curr[left] >= curr[right])
            return seg[idx] = left;
        return seg[idx] = right;
    }
    int getMax(int l, int r, int idx, int x, int y, int aidx, int bidx) {
        if(r < x || l > y)
            return -1;
        if(l >= x && r <= y)
            return seg[idx];
        int mid = l + (r - l) / 2;
        int c1 = getMax(l, mid, 2 * idx + 1, x, y, aidx, bidx);
        if(c1 != -1) {
            int ans = -1;
            if(curr[c1] > curr[aidx] && curr[c1] > curr[bidx])
                return c1;
        }
        int c2 = getMax(mid + 1, r, 2 * idx + 2, x, y, aidx, bidx);
        if(c2 != -1) {
            if(curr[c2] > curr[aidx] && curr[c2] > curr[bidx])
                return c2;
        }
        return -1;
    }
public:
    int n;
    vector<int> curr;
    vector<int> seg;
    SegmentTree(vector<int>& heights, int n) {
        this->n = n;
        seg.resize(4 * n, -1);
        curr = heights;
        build(0, n - 1, 0);
    }
    int query(int aidx, int bidx) {
        int l = bidx + 1, r = n - 1, md, ans = INT_MAX;
        while(l <= r) {
            md = l + (r - l) / 2;
            int left = getMax(0, n - 1, 0, l, md, aidx, bidx);
            if(left != -1) {
                ans = min(ans, left);
                r = md - 1;
                continue;
            }
            int right = getMax(0, n - 1, 0, md + 1, r, aidx, bidx);
            if(right != -1) {
                ans = min(right, ans);
                l = md + 1;
            }
            
            if(left == -1 && right == -1)
                break;
        }
        return ans == INT_MAX ? -1 : ans;
    }
    void printTree() {
        for(int i = 0; i < 4*n; i++) {
            cout << seg[i] << " ";
        }
    }
};

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        SegmentTree sg(heights, n);
        // sg.printTree();
        
        vector<int> ans;
        for(int i = 0; i < queries.size(); i++) {
            
            int aidx = queries[i][0], bidx = queries[i][1];
            aidx = min(queries[i][0], queries[i][1]);
            bidx = max(queries[i][0], queries[i][1]);
            if(heights[bidx] > heights[aidx] || aidx == bidx)
                ans.push_back(bidx);
            // else if(heights[bidx] == heights[aidx])
            //     ans.push_back(aidx);
            else {
                int res = sg.query(aidx, bidx);
                ans.push_back(res);
            }
        }

        return ans;
    }
};
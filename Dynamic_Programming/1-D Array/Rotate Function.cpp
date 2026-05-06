// https://leetcode.com/problems/rotate-function/description/

class Solution {
public:
    int n;
    int F(vector<int>& nums) {
        int val = 0;
        for(int i = 0; i < n; i++) {
            val += (i * nums[i]);
        }
        return val;
    }
    int maxRotateFunction(vector<int>& nums) {
        n = nums.size();
        
        // f(0) = 0.a0 + 1.a1 + .. + (n-2).an-2 + (n-1).an-1;
        // f(1) = 1.a0 + 2.a1 + .. + (n-1).an-2 + 0.an-1;
        // f(1) - f(0) = a0 + a1 + .. + an-2 - n.an-1 + an-1
        
        // f(1) - f(0) = (a0 + a1 + .. + an-2 + an-1) - n.an-1;
        // f(1) - f(0) = SUM - n.(last_el);
        
        // vector<int> fn(n, 0);
        int prev_fn = F(nums), curr_fn;
        int last_idx = n - 1;
        int sum_nums = accumulate(nums.begin(), nums.end(), 0);
        int maxValue = prev_fn;
        for(int i = 1; i < n; i++) {
            // fn[i] = fn[i - 1] + sum_nums - n * (nums[last_idx]);
            curr_fn = prev_fn + sum_nums - n * (nums[last_idx]);
            last_idx -= 1;
            prev_fn = curr_fn;
            maxValue = max(maxValue, curr_fn);
        }
        return maxValue;
        

    }
};
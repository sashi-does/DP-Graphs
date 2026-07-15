class Solution {
public:
    int n;
    int dp[201][201][201];
    int MOD = 1e9 + 7;
    // NO NEED OF THIS
    // int gcd(int a, int b) {
    //     if(a == 0 && b == 0)
    //         return 0;
    //     if(a == 0)
    //         return b;
    //     if(b == 0)
    //         return a;
    //     if(a >= b)
    //         return gcd(a % b, b);
    //     return gcd(a, b % a);
    // }
    int solve(vector<int>& nums, int i, int gcd1, int gcd2) {
        if(i >= n) {
            if(gcd1 == gcd2)
                // cnt++;
                return 1;
            return 0;
        }
        if(dp[i][gcd1][gcd2] != -1)
            return dp[i][gcd1][gcd2];
        // take i in seq1
        int a = solve(nums, i + 1, gcd(gcd1, nums[i]), gcd2);
        // take i in seq2
        int b = solve(nums, i + 1, gcd1, gcd(gcd2, nums[i]));
        // skip i
        int c = solve(nums, i + 1, gcd1, gcd2);

        return dp[i][gcd1][gcd2] = ((a + b) % MOD + c) % MOD;
    }
    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, 0, 0) - 1;
    }
};
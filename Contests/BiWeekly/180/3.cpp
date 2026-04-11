// https://leetcode.com/problems/minimum-operations-to-transform-array-into-alternating-prime/description/

class Solution {
public:
    bool isPrime(int n) {
        if(n <= 1)
            return false;
        for(int i = 2; i <= sqrt(n); i++) {
            if((n % i) == 0)
                return false;
        }
        return true;
    }
    int getNearestPrimesAbsolute(int num) {
        int base = num;
        base++;
        while(true) {
            if(isPrime(base)) {
                break;
            }
            base++;
        }
        return base - num;
        
    }
    int getNearestNonPrimesAbsolute(int num) {
        int base = num;
        base++;
        while(true) {
            if(!isPrime(base)) {
                break;
            }
            base++;
        }
        return base - num;
        
    }
    int minOperations(vector<int>& nums) {
        int ops = 0;
        for(int i = 0; i < nums.size(); i++) {
            bool prime = isPrime(nums[i]);
            if(i % 2 == 0) {
                if(!prime) {
                    ops += getNearestPrimesAbsolute(nums[i]);
                }
            }
            else {
                if(prime) {
                    ops += getNearestNonPrimesAbsolute(nums[i]);
                }
            }
        }
        return ops;
    }
};
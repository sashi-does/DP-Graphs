// https://leetcode.com/problems/count-digit-appearances/

class Solution {
public:
    int getCount(int num, int digit) {
        int count = 0;
        while(num) {
            if((num % 10) == digit)
                count++;
            num /= 10;
        }
        return count;
    }
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int times = 0;
        for(auto &num : nums) {
            times += getCount(num, digit);
        }
        return times;
    }
};
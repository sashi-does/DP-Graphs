# https://leetcode.com/problems/maximum-value-of-concatenated-binary-segments/

class Solution(object):
    
    def maxValue(self, nums1, nums0):
        def helper(a, b):
            if a + b > b + a:
                return -1
            return 1
        def stringToInt(str):
            exp = 0
            num = 0
            MOD = 10**9 + 7
            for i in range(len(str) - 1, -1, -1):
                if(str[i] == '1'):
                    num = (num + pow(2, exp, MOD)) % MOD
                exp += 1
            return num
        n = len(nums1)
        bin = []
        for i in range(n):
            bin.append((nums1[i] * '1') + (nums0[i] * '0'))
        bin.sort(key=cmp_to_key(helper))
        string = ""
        for part in bin:
            string += part
        
        return stringToInt(string)
        
        
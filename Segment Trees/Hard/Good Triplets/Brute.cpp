class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {

        long long cnt = 0;
        int n = nums1.size();
        unordered_map<int, int> store;
        vector<int> left, right;
        
        for(int i = 0; i < n; i++) {
            right.push_back(nums1[i]);
            store[nums2[i]] = i;
        }

        left.push_back(nums1[0]);
        reverse(right.begin(), right.end());
        right.pop_back();

        for(int i = 1; i < n - 1; i++) {
            int idx = store[nums1[i]];

            // validate left
            int l = 0, r = 0;
            for(int j = 0; j < left.size(); j++) {
                if(store[left[j]] < idx)
                    l++;
            }

            for(int j = 0; j < right.size(); j++) {
                if(store[right[j]] > idx)
                    r++;
            }
            
            cnt += (l * r);
            left.push_back(nums1[i]);
            right.pop_back();

        }
        return cnt;
    }
};
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int len = nums.size();
        int ret = 0;
        int addition = 0;
        unordered_map<int, int>sums;
        
        for (int i = 0; i < len; i++) {
            addition += nums[i];
            // this value has not been disclosed
            if (sums.find(addition) == sums.end()) {
                sums[addition] = i;
            }
            
            if (sums.find(addition - k) != sums.end()) {
                ret = max(ret, i - sums[addition - k]);
            }
            
            if (addition == k) 
                ret = max(ret, i + 1);
        }
        
        
        return ret;
    }
};

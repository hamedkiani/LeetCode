class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int sz = nums.size();
        if (sz == 0)
            return INT_MIN;
        if (sz == 1)
            return nums[0];

        int pre_maxVals, cur_maxVals;
        pre_maxVals = nums[0];
        cur_maxVals = nums[0];

        int pre_minVals = nums[0];
        int cur_minVals = nums[0];

        int res = nums[0];
        for (int i = 1 ; i < sz; i++){
            cur_maxVals = max(nums[i]*pre_maxVals, max(nums[i]*pre_minVals , nums[i]));
            cur_minVals = min(nums[i]*pre_maxVals, min(nums[i]*pre_minVals, nums[i]));
            pre_maxVals = cur_maxVals;
            pre_minVals = cur_minVals;
            res = max(res, cur_maxVals);
        }
        return res;
    }
};

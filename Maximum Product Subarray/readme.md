# LeetCode 152. Maximum Product Subarray

### Link: https://leetcode.com/problems/maximum-product-subarray/

### Difficulty: Medium

## Description

Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]

Output: 6

Explanation: [2,3] has the largest product 6.

Example 2:

Input: [-2,0,-1]

Output: 0

Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

## Code and Explanation

```cpp
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
```

### Time Complexity
O(N) we need to process the entire array

### Space Complexity
O(1)

### Useful Links

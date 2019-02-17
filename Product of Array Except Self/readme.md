# LeetCode 238. Product of Array Except Self

### Link: https://leetcode.com/problems/product-of-array-except-self/

### Difficulty: Medium

## Description

Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]

Output: [24,12,8,6]

Note: Please solve it without division and in O(n).

Follow up:

Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)

## Code and Explanation

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size();
        // if there is just one number in the array return an empty vector
        if (sz < 2)
            return vector<int>();

        // we need to vectors, one for keeping the product of all numbers at \
         the left of each number, and another one for keeping the product of \
          all numbers at the right part of each number.

        vector<int> res(sz,1);
        vector<int> temp(sz, 1);
        // compute the left products
        for (int i = 1; i < sz; i++)
            res[i] = res[i-1] * nums[i-1];
        // compute the right products

        for (int i = sz-2; i >= 0; i--)
            temp[i] = temp[i+1] * nums[i+1];

        // get the right and left products of each number, excluding itself
        for (int i = 0; i < sz; i++)
            res[i]*=  temp[i];

        return res;
}
};
```

### Time Complexity
O(N)

### Space Complexity
O(N)

### Useful Links
N/A

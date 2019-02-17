# LeetCode 268. Missing Number

### Link: https://leetcode.com/problems/missing-number/

### Difficulty: Easy

## Description

Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1:

Input: [3,0,1]

Output: 2

Example 2:

Input: [9,6,4,2,3,5,7,0,1]

Output: 8

## Code and Explanation

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        // sum of all numbers 0, ..., N

        int sum = (n*(n+1)/2);
        for(int i = 0; i < n; i++)
            sum -= nums[i];
        return sum;
    }
};
```

### Time Complexity
O(N) for the loop

### Space Complexity
O(1) no additional space is used

### Useful Links
N/A

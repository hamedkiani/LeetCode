# LeetCode 283. Move Zeroes

### Link: https://leetcode.com/problems/move-zeroes/

### Difficulty: Easy

## Description

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]

Output: [1,3,12,0,0]

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.

## Code and Explanation

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      // i indicates the latest index where is not 0, and j finds the next element which is not zero.
        int i = 0;
        int j = 0;
        int len = nums.size();
        if (len < 2)
            return;
        while(j < len){
            if (nums[j] != 0){
                nums[i] = nums[j];
                i++;
            }
            j++;
        }
        // i is the last index with non-zero values, after the loop there is no more non-zero value, so all we need is to set to zero the rest of elements till the end of the array
        while(i<len)
            nums[i++] = 0;
    }
};
```

### Time Complexity
O(N)

### Space Complexity
O(1)

### Useful Links
N/A

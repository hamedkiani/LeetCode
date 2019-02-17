# LeetCode 169. Majority Element

### Link: https://leetcode.com/problems/majority-element/

### Difficulty: Easy

## Description

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]

Output: 3

Example 2:

Input: [2,2,1,1,1,2,2]

Output: 2

## Code and Explanation

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
      // this can be solved either by brute force \
       with O(N^2) of time Complexity, and O(1) of \
        space. Another way is using hashtable to \
         count each number in the array. This \
          method has O(N) time and O(N) space \
           complexity.

        unordered_map<int, int> count;
        for (int i = 0; i < nums.size(); i++){
            if (++count[nums[i]] > nums.size()/2)
                return nums[i];
        }
        return -1;
    }
};
```

### Time Complexity
O(N) over the for loop.

### Space Complexity
O(N) for the unordered map

### Useful Links

[![](http://img.youtube.com/vi/zOyOwDEF1Rc/0.jpg)](http://www.youtube.com/watch?v=zOyOwDEF1Rc "")

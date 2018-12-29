# LeetCode 217. Contains Duplicate

### Link: https://leetcode.com/problems/contains-duplicate/

### Difficulty: Easy

## Description

Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:

Input: [1,2,3,1]

Output: true

Example 2:

Input: [1,2,3,4]

Output: false

Example 3:

Input: [1,1,1,3,3,4,3,2,4,2]

Output: true

## Code and Explanation

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums)
    {
        // if there is less than 2 numbers in the array, there would not be any duplicate
        if ( nums.size() < 2)
            return false;
        // we need to keep track of seen numbers, it could be done by using a\
         set or map. I used set. You can do it with O(1) memory, but you need\
          to have a nested loops with complexity of O(N^2), instead of O(N)\
           which is offered by this solution.

        unordered_set<int> s;

        // loop over the array, if the number was seen before (in the set)\
         return true, otherwise, add the number to the set for further checks.

        for (int i = 0; i < nums.size(); i++)
        {
            if (s.count(nums[i]) > 0)
                return true;
            else
                s.insert(nums[i]);
        }
        return false ;
    }
};
```

### Time Complexity

O(N): we need a loop over the array.

### Space Complexity

O(N): we need a set (or map) to count the numbers in the array.

### Useful Links

[![](http://img.youtube.com/vi/4ukiy-neq7M/0.jpg)](http://www.youtube.com/watch?v=4ukiy-neq7M "")

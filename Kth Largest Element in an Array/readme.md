# LeetCode 215. Kth Largest Element in an Array

### Link: https://leetcode.com/problems/kth-largest-element-in-an-array/

### Difficulty: Medium

## Description

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2

Output: 5

Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4

Output: 4

**Note:**

You may assume k is always valid, 1 ≤ k ≤ array's length.

## Code and Explanation

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
      // a naive approach is to sort the list and then return the list[k], it\
       can be done in O(nlogn) time and O(1) space.

      // another approach could be useing max-heap, the priority queue whose\
       node is the maximum value, and push/pop can be done in o(nlogn) with\
        O(n) space.

        priority_queue<int, vector<int>, less<int>> Q;
        for(int i = 0; i < nums.size(); i++)
            Q.push(nums[i]);

        // after pushing all numbers into the PQ, we have the maximum number in\
         the root. By removing/poping K-1 number, the Kth maximum number is in\
          the root, and can be returned as the solution.

          // this approach, however, is not optimal, if the length of nums is\
           so long, then putting all numbers in PQ (as maxheap) is expensive.

          // Another approach could be using minheap, this approach is\
           explained in the attached video link.

        while(k>1)
        {
            Q.pop();
            k--;
        }
        return Q.top();
    }
};
```

### Time Complexity

O(NlogN): for PQ pushing/popping

### Space Complexity

O(N): for creating the PQ.

### Useful Links

[![](http://img.youtube.com/vi/FrWq2rznPLQ/0.jpg)](http://www.youtube.com/watch?v=FrWq2rznPLQ "")

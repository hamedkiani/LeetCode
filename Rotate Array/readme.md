# LeetCode 189. Rotate Array

### Link: https://leetcode.com/problems/rotate-array/

### Difficulty: Easy

## Description

Given an array, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: [1,2,3,4,5,6,7] and k = 3

Output: [5,6,7,1,2,3,4]

Explanation:

rotate 1 steps to the right: [7,1,2,3,4,5,6]

rotate 2 steps to the right: [6,7,1,2,3,4,5]

rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:

Input: [-1,-100,3,99] and k = 2

Output: [3,99,-1,-100]

Explanation:

rotate 1 steps to the right: [99,-1,-100,3]

rotate 2 steps to the right: [3,99,-1,-100]

Note:

Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

Could you do it in-place with O(1) extra space?

## Code and Explanation

```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // using queue        
        if (nums.size()<2 || k <= 0)
            return;

        queue<int> q;
        for (int i = nums.size()-1; i >=0; i--){
            q.push(nums[i]);
        }

        for (int i = 0; i < k; i++){
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        for (int i =  nums.size()-1; i >=0; i--){
            nums[i] = q.front();
            q.pop();
        }        
    }
};
```

### Time Complexity
O(N) for processing the entire list

### Space Complexity
O(N) for the queue

### Useful Links

[![](http://img.youtube.com/vi/viaha1SnpT4/0.jpg)](http://www.youtube.com/watch?v=viaha1SnpT4 "")

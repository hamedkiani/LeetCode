# LeetCode 70. Climbing Stairs

### Link: https://leetcode.com/problems/climbing-stairs/

### Difficulty: Easy

## Description

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

Example 1:

Input: 2

Output: 2

Explanation: There are two ways to climb to the top.

    1. 1 step + 1 step
    2. 2 steps

Example 2:

Input: 3

Output: 3

Explanation: There are three ways to climb to the top.

    1. 1 step + 1 step + 1 step
    2. 1 step + 2 steps
    3. 2 steps + 1 step

## Code and Explanation

```cpp
class Solution {
public:
    int climbStairs(int n)
    {
       // if there is just one step, you can take [1] step, if there are two steps, you climb in two ways, [[2], [1,1]]
       if (n==1)
            return 1;
       else if (n==2)
            return 2;

        // otherwise, if the number of steps are more than 2, and you are at step i, you can take one step from step i-1, or two steps from step i-2.

        // so all we need it to keep the number of ways we can climb from step i-1, and i-2. This is done by using two variables (you can use an array, but it costs additional O(N) memory) *a* and *b*. We need to update *a* and *b* at each step. This is same as Fibonacci series. This is done as following.

        int a = 1;
        int b = 2;
        int c = 1;
        for(int i = 2; i < n; i++)
        {
          c = a + b;
          a = b;
          b = c;
        }
        return c;
    }
};
```

### Time Complexity

O(N): there is a loop of N.

### Space Complexity

O(1): no additional space is used.

### Useful Links

[![](http://img.youtube.com/vi/CFQk7OQO_xM/0.jpg)](http://www.youtube.com/watch?v=CFQk7OQO_xM "")

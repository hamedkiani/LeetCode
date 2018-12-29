# LeetCode 11. Container With Most Water

### Link: https://leetcode.com/problems/container-with-most-water/

### Difficulty: Medium

## Description

Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

Example:

Input: [1,8,6,2,5,4,8,3,7]

The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Output: 49

## Code and Explanation

```cpp
class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int sz = height.size();
        if (sz < 2)
            return 0;

        // the main point of this problem is to find two highest bars with maximum distance. Considering the tank as a rectangle, the area is h*w, such that h is the minimum of two highest bars, and w is the distance between these two bars.

        // Two bars are supposed to be the right and left side of the tank, so\
         we need two indicators, left (l), and right (r), initialized with 0,\
          and array.size()-1 (the last index).

        int l = 0;
        int r = sz-1;
        // we need to keep track of maximum area found so far. which is\
         initialized by 0 (we need to find max!).

        int maxVal = 0;
        // over a loop, we process the l and r indices and compute current\
         maxumum area.

        while(l < r)
        {
            // we use min(height[l] , height[r]), because the minimum of two\
             bars shows the height of water between these two bars.

            maxVal = max(maxVal, min(height[l] , height[r]) * (r-l));

            // we do a greedy strategy here, we want to move right and left\
             forward and backward to find higher bars.

            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        // finally we return the max area.
        return maxVal;
    }
};
```
### Time Complexity

O(N), a loop over the array.

### Space Complexity

O(1): no additional memory is used.

### Useful Links

[![](http://img.youtube.com/vi/K8SF4YadH0Q/0.jpg)](http://www.youtube.com/watch?v=K8SF4YadH0Q "")

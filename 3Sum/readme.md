# LeetCode 15. 3Sum

### Link: https://leetcode.com/problems/3sum

### Difficulty: Medium

## Description
Given an array *nums* of *n* integers, are there elements *a* , *b* , *c*  in *nums* such that *a + b + c = 0* ?

Find all unique triplets in the array which gives the sum of zero.

**Note:**

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:

    [

      [-1, 0, 1],

      [-1, -1, 2]

    ]

## Code and Explanation

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        // we need to sort the array, we start from the left most number (a) and see if there are two numbers on the right (b,c) such that b + c = -a
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int target = -nums[i];
            int front = i + 1;
            int back = nums.size() - 1;
            //  if target < 0 (nums[i] > 0), there is no chance to find two numbers that b + c = target, because all numbers on the right side of target are positive and two positives can be sum up to a negative value.                
            if(target < 0)
            {
                break;
            }
            // let's check the numbers at front and back and see if their summation is equal, bigger or smaller than target.
            while (front < back) {
                int sum = nums[front] + nums[back];
                // if sum < target, we need to increase the summation, thus, move front forward.
                // if sum > target, we need to decrease the summation, thus, move back backward
                if (sum < target)
                    front++;
                else if (sum > target)
                    back--;
                else { // target == sum, we found an answer here.
                    vector<int> triplet(3, 0);
                    triplet[0] = nums[i];
                    triplet[1] = nums[front];
                    triplet[2] = nums[back];
                    res.push_back(triplet);

                // Processing duplicates of Number at front
                // Rolling the front pointer to the next different number forwards
                    while (front < back && nums[front] == triplet[1]) front++;

                // Processing duplicates of Number at back
                // Rolling the back pointer to the next different number backwards
                    while (front < back && nums[back] == triplet[2]) back--;
                }
            }

        // Processing duplicates of Number at target
            while (i + 1 < nums.size() && nums[i + 1] == nums[i])
                i++;
        }
        return res;
    }
};
```

### Time Complexity

**O(N^2)**

There are two nested loops, one over *i* and another one over *front* and *back*.

### Space Complexity

**O(1)**

No additional space is required, the output *res* is not considered as required memory.

### Useful Links

[![](http://img.youtube.com/vi/-AMHUdZc9ss/0.jpg)](http://www.youtube.com/watch?v=-AMHUdZc9ss "")


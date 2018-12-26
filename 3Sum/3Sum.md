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
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; i++) {

            int target = -nums[i];
            int front = i + 1;
            int back = nums.size() - 1;

            if(target < 0)
            {
                break;
            }

            while (front < back) {
                int sum = nums[front] + nums[back];
                // Finding answer which start from number num[i]
                if (sum < target)
                    front++;
                else if (sum > target)
                    back--;
                else {
                    vector<int> triplet(3, 0);
                    triplet[0] = nums[i];
                    triplet[1] = nums[front];
                    triplet[2] = nums[back];
                    res.push_back(triplet);

                // Processing duplicates of Number 2
                // Rolling the front pointer to the next different number forwards
                    while (front < back && nums[front] == triplet[1]) front++;

                // Processing duplicates of Number 3
                // Rolling the back pointer to the next different number backwards
                    while (front < back && nums[back] == triplet[2]) back--;
                }
            }

        // Processing duplicates of Number 1
            while (i + 1 < nums.size() && nums[i + 1] == nums[i])
                i++;
        }
        return res;
    }
};
```

### Time Complexity

### Space Complexity

### Useful Links

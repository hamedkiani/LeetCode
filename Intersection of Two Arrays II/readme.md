# LeetCode 350. Intersection of Two Arrays II

### Link: https://leetcode.com/problems/intersection-of-two-arrays-ii/

### Difficulty: Easy

## Description

Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]

Output: [2,2]

Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]

Output: [4,9]

**Note:**

Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.

Follow up:

1. What if the given array is already sorted? How would you optimize your algorithm?
2. What if nums1's size is small compared to nums2's size? Which algorithm is better?
3. What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

## Code and Explanation

```cpp
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
      // output is a list of numbers
        vector<int> res;
        // this approach is based on sorted lists. This can be done by O(NlogN) and inplace

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        // we start from the first digits of both sorted lists
        int l1 = 0;
        int l2 = 0;
        // if both lists have the same numbers, add it to the output list
        while(l1 < nums1.size() && l2 < nums2.size())
        {
            if (nums1[l1] == nums2[l2])
            {
                res.push_back(nums1[l1]);
                l1++; l2++;
            }
            // else if number of list1 is bigger than list2, then move forward the list2
            else if (nums1[l1] > nums2[l2])
                l2++;
                // else if number of list2 is bigger than list1, then move forward the list1
            else
                l1++;
        }
        return res;
    }
};
```
### Time Complexity

O(NlogN): for sorting both lists.

### Space Complexity

O(1): the space for output is not considered.

### Useful Links

[![](http://img.youtube.com/vi/B5CaAmN8QSQ/0.jpg)](http://www.youtube.com/watch?v=B5CaAmN8QSQ "")

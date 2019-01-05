# LeetCode 287. Find the Duplicate Number

### Link: https://leetcode.com/problems/find-the-duplicate-number/

### Difficulty: Medium

## Description

Given an array *nums* containing *n + 1* integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Example 1:

Input: [1,3,4,2,2]

Output: 2

Example 2:

Input: [3,1,3,4,2]

Output: 3

**Note:**

1. You must not modify the array (assume the array is read only).
2. You must use only constant, O(1) extra space.
3. Your runtime complexity should be less than O(n2).
4. There is only one duplicate number in the array, but it could be repeated more than once.

## Code and Explanation

```cpp
// there are several ways to solve this problem. We can use a nested loops to\
 find duplicate number, with O(N^2) time complexity, we can use hashtable with\
  O(N) time and space complexity.

// this problem, however, has some properties and limitations which mentioned\
 in the note section. Main restriction is to have complexity less than O(N^2)\
  and no additional space.

//  we solve this problem by considering such constraints.
// This problem is similar to finding a loop in linkedlist. In linkedlist,\
 basically, if there is no loop, for N nodes there are N-1 links. Each node has\
  maximum one input and one output link. If there is a node with more than one\
   input link, then there is a loop.

// similarly, in this problem, there are N+1 numbers which are between 1 and N. If we store this N +1 numbers in a linkedlist with no duplication, there will be a node with two input links. So we can use the same solution of finding loop in the linkedlist to find the duplicate number in this list of numbers, which named as Floyd’s Cycle detection algorithm.

In this problem, the links are the
class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
        // we use two indices one has one jump and another has two jumps. they are initialized by the same number are nums[0]

        int slow = nums[0];
        int fast = nums[0];

        // we move these two indices till they indicate the same number. This means that there is a duplicate number

        while(true)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast)
                break;
        }
        // we re-initialize the slow (or fast) to nums[0] (beginning of the\
           list) and move fast and slow indices till they are same. Now, both\
            are indicating the duplicate Number

        slow = nums[0];

        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
```

### Time Complexity

O(N): refer to the link provided for Floyd’s Cycle detection algorithm.

### Space Complexity

O(1)

### Useful Links

https://stackoverflow.com/questions/47193225/runtime-complexity-of-floyds-cycle-detection

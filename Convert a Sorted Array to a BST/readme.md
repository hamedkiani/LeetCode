# LeetCode 108. Convert a Sorted Array to a BST

### Link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

### Difficulty: Easy

## Description

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array:

[-10,-3,0,5,9]

One possible answer is:

[0,-3,9,-10,null,5], which represents the following height balanced BST:

          0
         / \
       -3   9
       /   /
     -10  5

## Code and Explanation

```cpp
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        // the main point of this problem is knowing that in BST, at the value\
         at each node is bigger than values on its left subtree, and smaller\
          than its right subtree. Moreover, in this problem, the array is\
           sorted. So the number in the middle of the array is bigger than its\
            left side, and smaller than its right side. By considering these\
             two facts, this problem can be solved recursively, by putting the\
              number at the middle of the array on the root, and recursively\
               creating its left and right subtree by calling the recursive\
                function over the left and right sides of the number (at the root).

        // Call the helper function, with the array and its begin and end\
         indices.

        return helper(nums, 0, nums.size()-1);
    }

    TreeNode* helper(vector<int> nums, int low, int high)
    {
        // ending condition: if thigh < low just return NULL. There is no/
         number to process.
        if (high  < low)
            return NULL;

        // find the medium number here,
        int mid = low + (high - low) /2;

        // create a node for the mid number.
        TreeNode* temp = new TreeNode(nums[mid]);

        // process the left side of the number (low,...,mid-1) as the left\
         subtree

        temp->left = helper(nums, low, mid-1);

        // process the right side of the number (mid+1,...,high) as the right\
         subtree

        temp->right = helper(nums, mid+1, high);

        // return temp, as the root of the BST, with balanced height (logN)
        return temp;
    }
};
```

### Time Complexity

the complexity of T(n) = 2T(n/2) + c, which is O(N). Please check the link at\
 Useful Links

### Space Complexity

O(1): no additional memory is explicitly used, but because of the recursive\
 nature of the solution, there is stack memory (of the system- O(logN)) used to\
  remember the recursion.

### Useful Links

[![](http://img.youtube.com/vi/VCTP81Ij-EM/0.jpg)](http://www.youtube.com/watch?v=VCTP81Ij-EM "")

for time Complexity: https://www.quora.com/What-is-the-complexity-of-T-n-2T-n-2-+-C-using-recurrence-equations

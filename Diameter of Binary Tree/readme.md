# LeetCode 543. Diameter of Binary Tree

### Link: https://leetcode.com/problems/diameter-of-binary-tree/

### Difficulty: Easy

## Description

Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree

              1
             / \
            2   3
           / \     
          4   5    

Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

**Note:** The length of path between two nodes is represented by the number of edges between them.

## Code and Explanation

```cpp
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root)
    {
        // if node is null then return 0- stopping condition
        if (!root)
            return 0;

        //otherwise, compute the height of left subtree and right subtree
        //  the maximum diameter is the maximum summation of the max dim of left subtree + max dim of right subtree

        int lh = height(root->left);
        int rh = height(root->right);

        // recursively compute the maximum diameter of the left and right\
         subtree

        int ld = diameterOfBinaryTree(root->left);
        int rd = diameterOfBinaryTree(root->right);

        // return the maximum between lh+rh (diameter of current node), and the\
         maximum of the left and right subtree diameter

        return max(lh+rh, max(ld, rd));
    }

    int height(TreeNode * root)
    {
        if (!root)
            return 0;
        return 1 + max(height(root->right), height(root->left));

    }
};
```

### Time Complexity

O(N^2)

There are two parts in this solution, recursively computing the height of each\
 node, which in the worse case it takes O(N), and average case of O(logN) if\
  the tree is balanced.

The second part is recursively computing the maximum diameter of the BT, which runs for each node, so the worse case is O(N^2).

### Space Complexity

No additional space is used in this solution. However, because of the nature of\
 recursive functions, we need to keep the recursion in the system stack, which\
  in the worse case is O(N).

### Useful Links

[![](http://img.youtube.com/vi/zUgxaZApKWA/0.jpg)](http://www.youtube.com/watch?v=zUgxaZApKWA "")

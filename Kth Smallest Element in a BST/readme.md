# LeetCode 230. Kth Smallest Element in a BST

### Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/

### Difficulty: Medium

## Description

Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Example 1:

Input: root = [3,1,4,null,2], k = 1

```
   3
  / \
 1   4
  \
   2
```
Output: 1

Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
```
       5
      / \
     3   6
    / \
   2   4
  /
 1
```
Output: 3

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

## Code and Explanation

```cpp
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if (root == NULL || k < 0 )
            return -1;

// this is similar to dfs search, when we pop an element from the stack, we\
 actually remove the smallest values in the BST, so when we pop Kth elements\
  from stack, actually we remove the kth smallest of the BST.

// another way, is inorder traversal, we will have a sorted list, whose the kth element is the kth smallest one.

        stack<TreeNode* > stk;
        TreeNode * temp = root;
        while(temp || !stk.empty()){
            while (temp){
                stk.push(temp); temp = temp->left;
            }
            temp = stk.top();
            stk.pop();
            if (--k == 0)
                return temp->val;
            temp = temp->right;
        }
    }   
};

```

### Time Complexity
O(N), we need to process all N nodes in the worse case.

### Space Complexity
O(N) space needed for the stack

### Useful Links

N/A

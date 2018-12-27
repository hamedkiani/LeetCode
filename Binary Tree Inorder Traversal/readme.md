# LeetCode 94. Binary Tree Inorder Traversal

### Link: https://leetcode.com/problems/binary-tree-inorder-traversal/

### Difficulty: Medium

## Description

Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]

     1
      \
       2
      /
     3

Output: [1,3,2]

## Code and Explanation

```cpp
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> res;
        helper_iter(root, res);
        return res;
    }
    // iterative
    // for iterative, we need a stack to keep visited nodes, and a temp to track nodes,
    // temp is pointing Root, we keep traversing the left node of temp till it gets NULL.
    // then we point temp to the top of stack, add it to the output list, and pop from stack, and move temp to right child
    void helper_iter(TreeNode* root, vector<int> & res)
    {
        if (!root)
            return;
        stack<TreeNode* > stk;
        TreeNode* temp = root;
        while(temp || !stk.empty()){
            while(temp){
                stk.push(temp); temp = temp->left;
            }
            temp = stk.top();
            res.push_back(temp->val);
            stk.pop();
            temp = temp->right;
        }
    }    
};
```

### Time Complexity

O(N): each node is processed once

### Space Complexity

O(N), because of the stack used.

### Useful Links

[![](http://img.youtube.com/vi/nzmtCFNae9k/0.jpg)](http://www.youtube.com/watch?v=nzmtCFNae9k "")

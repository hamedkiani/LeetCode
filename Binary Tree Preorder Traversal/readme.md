# LeetCode 144. Binary Tree Preorder Traversal

### Link: https://leetcode.com/problems/binary-tree-preorder-traversal/

### Difficulty: Medium

## Description

Given a binary tree, return the preorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]

       1
        \
         2
        /
       3

Output: [1,2,3]

**Follow up:** Recursive solution is trivial, could you do it iteratively?

## Code and Explanation

```cpp
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> res;
        helper(root, res);
        return res;
    }

    void helper(TreeNode* root, vector<int> &res)
    {
        if (!root)
            return;

        // preorder traversal is same as inorder traversal. In both we use stack, we traverse the left child before right child. The only difference is in preorder we print the node value when we push it to stack (parent first then left and right child), while in inorder, we print the node value when we pop it from the stack (left child, parent, and right child).

        stack<TreeNode*> stk;
        TreeNode* temp = root;
        while(temp || !stk.empty()){
            while(temp)
            {
                // we push the node when we visit it
                res.push_back(temp->val);
                stk.push(temp);
                temp = temp->left;
            }
            // if there is no left child, we process the right child of the node on the top of the stack.

            temp = stk.top();
            stk.pop();
            temp = temp->right;
        }
        return;
    }
};
```

### Time Complexity

O(N): each node is processed just once.

### Space Complexity

O(N): we used an additional stack of size N (worse case)

### Useful Links

[![](http://img.youtube.com/vi/elQcrJrfObg/0.jpg)](http://www.youtube.com/watch?v=elQcrJrfObg "")

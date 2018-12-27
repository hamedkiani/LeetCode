# LeetCode 145. Binary tree Postorder Traversal

### Link: https://leetcode.com/problems/binary-tree-postorder-traversal/

### Difficulty: Hard

## Description

Given a binary tree, return the postorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]

       1
        \
         2
        /
       3

Output: [3,2,1]

**Follow up:** Recursive solution is trivial, could you do it iteratively?

## Code and Explanation

```cpp
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> res;
        if (root == NULL)
            return res;
        helper_iter(root, res);
        return res;
    }

     void helper_iter(TreeNode * root, vector<int> & res)
     {
         if (!root)
             return;

         // the main trick of postorder BT traversal is using two stacks. These two stacks work to gether closely to (1) process all nodes, and (2) keep the order of postorder traversal as left-child, right-child and root.  

         stack<TreeNode*> s1;
         stack<TreeNode*> s2;
         TreeNode* temp = root;

         // one stack is initialized by the root, over a loop on the stack, we pop from the stack and push to another stack.
         // To process the correct order of children, we push the right and left child of the popped node into the first stack.
         // When the loop ends, we visited all nodes in the first stack, and the address of all nodes are saved in the second stack in the post-order order.
         // All we need is to print out the nodes in the second stack as the postorder traversal of the given binary tree.

         s1.push(temp);
         while(!s1.empty()){
             temp = s1.top();
             s1.pop();
             s2.push(temp);
             if(temp->left)
                 s1.push(temp->left);
             if(temp->right)
                 s1.push(temp->right);
         }
         while(!s2.empty()){
             temp = s2.top();
             res.push_back(temp->val);
             s2.pop();
         }
    }
};
```

### Time Complexity

O(N): each node is processed just once.

### Space Complexity

O(N): we use two stack of size N.

### Useful Links

[![](http://img.youtube.com/vi/qT65HltK2uE/0.jpg)](http://www.youtube.com/watch?v=qT65HltK2uE "")

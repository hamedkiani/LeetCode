# LeetCode 101. Symmetric Tree

### Link: https://leetcode.com/problems/symmetric-tree/

### Difficulty: Easy

## Description

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
```
    1
   / \
  2   2
 / \ / \
3  4 4  3
```

But the following [1,2,2,null,3,null,3] is not:
```
    1
   / \
  2   2
   \   \
   3    3
```
Note:

Bonus points if you could solve it both recursively and iteratively.

## Code and Explanation

```cpp
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        queue<TreeNode*> q;
        q.push(root->right);
        q.push(root->left);

        while(!q.empty()){
            TreeNode* tl = q.front(); q.pop();
            TreeNode* tr = q.front(); q.pop();
            if (!tl && !tr)
                continue;
            if (tl && tr && tl->val != tr->val)
                return false;
            if ((!tl && tr) || (tl && !tr))
                return false;
            q.push(tl->left);
            q.push(tr->right);
            q.push(tl->right);
            q.push(tr->left);
        }//while q.empty()
        return true;
    }

    // second approach- recursive
    bool helper(TreeNode* l, TreeNode *r){
        if (!l && !r)
            return true;
        if(!l || !r)
            return false;
        if (l->val != r->val )
            return false;
        return (helper(l->left, r->right) && helper(l->right, r->left));
    }
};

```

### Time Complexity
Recursive: O(N)
Iterative: O(N)

### Space Complexity
Recursive: O(N) for recursive stack
Iterative: O(N) for the queue

### Useful Links
N/A

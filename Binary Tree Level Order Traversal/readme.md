# LeetCode 102. Binary Tree Level Order Traversal

### Link: https://leetcode.com/problems/binary-tree-level-order-traversal/

### Difficulty: Medium

## Description

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],

        3
       / \
      9  20
        /  \
       15   7

return its level order traversal as:

    [
      [3],
      [9,20],
      [15,7]
    ]

## Code and Explanation

```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> res;
        if (!root)
            return res;
        TreeNode * temp = root;
        // the core of BFS or level order traversal is using a queue to keep track of each level
        queue<TreeNode*> q;
        // the queue is initialized by the root.
        q.push(temp);
        // we loop over the queue as long as the queue is not empty (there is a node in tree to be processed)
        while(!q.empty())
        {
            // we get the size of the queue, this indicates the number of nodes at each level. When we start the loop, if the queue is not empty, there is one node in the queue, this means that there is one node in the first level.
            int c = q.size();
            // l is a vector and keeps the nodes (values) at each level
            vector<int> l;
            // since size of the queue shows the number of nodes in each level, we loop over the size and:
            // (1) retrieve the front node, and push its value to the list l
            // (2) pop from the queue,
            // (3) decrease the c, and
            // (4) check if the left/right child of the node is not empty, then we push it to the queue.
            while(c > 0)
            {
                temp = q.front(); q.pop(); c--; l.push_back(temp->val);
                if (temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            // after processing each level, we push back the vector to the 2D vector "res"
            res.push_back(l);
        }
        return res;
    }
};
```

### Time Complexity

O(N): each node is processed once

### Space Complexity

O(N): a queue is required to keep the visited nodes for next-level processing.

### Useful Links

[![](http://img.youtube.com/vi/9PHkM0Jri_4/0.jpg)](http://www.youtube.com/watch?v=9PHkM0Jri_4 "")

[![](http://img.youtube.com/vi/1t7-G3ls7VI/0.jpg)](http://www.youtube.com/watch?v=1t7-G3ls7VI "")

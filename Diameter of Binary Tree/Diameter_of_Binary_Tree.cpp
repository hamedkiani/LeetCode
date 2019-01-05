class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root)
    {
        if (!root)
            return 0;
        int lh = height(root->left);
        int rh = height(root->right);

        int ld = diameterOfBinaryTree(root->left);
        int rd = diameterOfBinaryTree(root->right);
        return max(lh+rh, max(ld, rd));
    }

    int height(TreeNode * root)
    {
        if (!root)
            return 0;
        return 1 + max(height(root->right), height(root->left));

    }
};

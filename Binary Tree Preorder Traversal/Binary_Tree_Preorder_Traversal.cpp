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
        stack<TreeNode*> stk;
        TreeNode* temp = root;
        while(temp || !stk.empty())
        {
            while(temp)
            {
                res.push_back(temp->val);
                stk.push(temp);
                temp = temp->left;
            }
            temp = stk.top();
            stk.pop();
            temp = temp->right;
        }
        return;
    }
};

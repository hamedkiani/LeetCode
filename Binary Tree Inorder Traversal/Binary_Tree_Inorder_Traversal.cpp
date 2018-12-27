class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> res;
        helper_iter(root, res);
        return res;
    }
    // iterative
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

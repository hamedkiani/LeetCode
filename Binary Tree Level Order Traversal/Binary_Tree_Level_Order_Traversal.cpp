class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> res;
        if (!root)
            return res;
        TreeNode * temp = root;
        queue<TreeNode*> q;
        q.push(temp);
        while(!q.empty()){
            int c = q.size();
            vector<int> l;
            while(c > 0)
            {
                temp = q.front(); q.pop(); c--; l.push_back(temp->val);
                if (temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            res.push_back(l);
        }
        return res;
    }
};

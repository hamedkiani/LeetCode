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
        
     void helper_iter(TreeNode * root, vector<int> & res){
         if (!root)
             return;
         stack<TreeNode*> s1; stack<TreeNode*> s2;
         TreeNode* temp = root;
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

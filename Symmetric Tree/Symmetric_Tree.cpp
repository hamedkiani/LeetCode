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

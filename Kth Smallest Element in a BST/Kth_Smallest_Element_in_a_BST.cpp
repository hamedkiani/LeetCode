class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if (root == NULL || k < 0 )
            return -1;

        stack<TreeNode* > stk; TreeNode * temp = root;
        while(temp || !stk.empty()){
            while (temp){
                stk.push(temp); temp = temp->left;
            }
            temp = stk.top();
            stk.pop();
            if (--k == 0)
                return temp->val;
            temp = temp->right;
        }
    }   
};

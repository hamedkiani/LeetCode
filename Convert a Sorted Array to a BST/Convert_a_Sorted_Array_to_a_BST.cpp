class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        int l = nums.size();
        if (l == 0)
            return NULL;
        if (l == 1)
        {
            TreeNode* temp  = new TreeNode(nums[0]);
            return temp;
        }
        return helper(nums, 0, l-1);
    }
    TreeNode* helper(vector<int> nums, int low, int high)
    {
        if (high  < low)
            return NULL;
        int mid = low + (high - low) /2;
        TreeNode* temp = new TreeNode(nums[mid]);
        temp->left = helper(nums, low, mid-1);
        temp->right = helper(nums, mid+1, high);
        return temp;
    }
};

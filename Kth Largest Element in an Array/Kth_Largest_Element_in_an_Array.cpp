class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        priority_queue<int, vector<int>, less<int>> Q;
        for(int i = 0; i < nums.size(); i++)
            Q.push(nums[i]);

        while(k>1)
        {
            Q.pop();
            k--;
        }
        return Q.top();
    }
};

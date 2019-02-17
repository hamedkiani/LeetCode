class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int sz = nums.size();
        if (sz < 2)
            return vector<int>();

        vector<int> res(sz,1);
        vector<int> temp(sz, 1);

        for (int i = 1; i < sz; i++)
            res[i] = res[i-1] * nums[i-1];

        for (int i = sz-2; i >= 0; i--)
            temp[i] = temp[i+1] * nums[i+1];
        for (int i = 0; i < sz; i++)
            res[i]*=  temp[i];
        return res;
}
};

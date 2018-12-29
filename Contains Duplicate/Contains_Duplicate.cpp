class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if ( nums.size() < 2)
            return false;
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++){
            if (s.count(nums[i]) > 0)
                return true;
            else
                s.insert(nums[i]);
        }
        return false ;
    }
};

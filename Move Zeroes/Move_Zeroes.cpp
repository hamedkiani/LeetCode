class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int len = nums.size();
        if (len < 2)
            return;
        while(j < len){
            if (nums[j] != 0){
                nums[i] = nums[j];
                i++;
            }
            j++;
        }
        while(i<len)
            nums[i++] = 0;
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size()<2 || k <= 0)
            return;
        queue<int> q;
        for (int i = nums.size()-1; i >=0; i--){
            q.push(nums[i]);
        }
        for (int i = 0; i < k; i++){
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        for (int i =  nums.size()-1; i >=0; i--){
            nums[i] = q.front();
            q.pop();
        }
    }

};

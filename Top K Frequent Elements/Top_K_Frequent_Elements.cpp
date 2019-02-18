class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        int sz = nums.size();
        if (!sz || !k)
            return vector<int>();

        unordered_map<int, int> hash;
        int maxF = INT_MIN;
        for(int i = 0 ; i < sz; i++){
            hash[nums[i]]++;
            maxF = max(maxF, hash[nums[i]]);
        }

        vector<vector<int>> bucket(maxF+1);
        for(auto itr = hash.begin(); itr != hash.end(); itr++){
            bucket[itr->second].push_back(itr->first);
        }
        vector<int> res;
        for (int i = maxF; i >=0; i--){
            int j = bucket[i].size()-1;
            while(j>=0 && res.size() < k){
                res.push_back(bucket[i][j]);
                j--;
            }
        }
        return res;
    }
};

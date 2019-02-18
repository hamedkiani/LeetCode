# LeetCode 347. Top K Frequent Elements

### Link: https://leetcode.com/problems/top-k-frequent-elements/

### Difficulty: Medium

## Description

Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2

Output: [1,2]

Example 2:

Input: nums = [1], k = 1

Output: [1]

Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

## Code and Explanation

```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      // our strategy does not use sorting, so we can keep the compuation less than O(N log N)
        int sz = nums.size();
// if k==0 or nums is empty return an empty verctor
        if (!sz || !k)
            return vector<int>();
        // we use a hashtable to count each number occurrences
        unordered_map<int, int> hash;
        // we also need to find the maximum occurrences in the vector
        int maxF = INT_MIN;
        for(int i = 0 ; i < sz; i++){
            hash[nums[i]]++;
            maxF = max(maxF, hash[nums[i]]);
        }
        // bucket has the length of maxF+1 (including 0) and we want to push \
         each number in its occurrence indicator [0, ..., maxF]
        vector<vector<int>> bucket(maxF+1);
        // here we go over the hashtable and push_back each number to its corresponding occurrence
        for(auto itr = hash.begin(); itr != hash.end(); itr++){
            bucket[itr->second].push_back(itr->first);
        }
        // res is the out put and a vector of int, including top K frequent numbers
        vector<int> res;
        // we start from the maximum occurrences and add its corresponding numbers till we get K numbers
        for (int i = maxF; i >=0; i--){
            int j = bucket[i].size()-1;
            while(j>=0 && res.size() < k){
                res.push_back(bucket[i][j]);
                j--;
            }
        }
        // now return the res :)
        return res;
    }
};
```

### Time Complexity
O(N) just for loops

### Space Complexity
O(N) we use 2D vector but we put just N number in it,

### Useful Links

[![](http://img.youtube.com/vi/EYFcQRwcqk0/0.jpg)](http://www.youtube.com/watch?v=EYFcQRwcqk0 "")

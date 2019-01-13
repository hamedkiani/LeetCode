# LeetCode 49. Group Anagrams

### Link: https://leetcode.com/problems/group-anagrams/

### Difficulty: Medium

## Description

Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],

Output:

    [
      ["ate","eat","tea"],
      ["nat","tan"],
      ["bat"]
    ]

**Note:**

All inputs will be in lowercase.
The order of your output does not matter.

## Code and Explanation
```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int ln = strs.size();
        // output is vector of list of strings.
        vector< vector<string>> res;
         if (ln == 0)
             return res;
        // we use a hashtable with key of the sorted string, and a value of list of strings
        unordered_map<string, vector<string>> str_map;
        for(int i = 0; i < ln; i++){
            string temp = strs[i];
            // sortting the string needs O(NlogN) Complexity
            sort(temp.begin(), temp.end());
            str_map[temp].push_back(strs[i]);
        }
        // O(N) for generating the result from the hashtable
        for (auto sm = str_map.begin(); sm!=str_map.end(); sm++){
            res.push_back(sm->second );
        }
        return res;
    }
};
```

### Time Complexity

O(N^2 log N): O(NlogN) for sorting each string, and we do that for N strings.

### Space Complexity

O(N): the space needed for hashtable. We can do sorting in place with O(1) space.

### Useful Links

N/A

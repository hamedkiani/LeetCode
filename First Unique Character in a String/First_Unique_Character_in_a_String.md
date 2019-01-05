# LeetCode 387. First Unique Character in a String

### Link: https://leetcode.com/problems/first-unique-character-in-a-string/

### Difficulty: Easy

## Description

Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"

return 0.

s = "loveleetcode",

return 2.

**Note:** You may assume the string contain only lowercase letters.

## Code and Explanation

```cpp
class Solution {
public:
    int firstUniqChar(string s) {
      // we use the map to keep count of each char in the string
        unordered_map<char, int> hash;        

        for(int i = 0; i < s.length(); i++)
        {
            hash[s[i]]++;
        }
        // return the first char with just one occurrence.
        for (int i=0; i < s.length(); i++){
            if (hash[s[i]]==1)
                return i;
        }
        return -1;

    }
};
```
### Time Complexity

O(N): need a loop on the string.

### Space Complexity

O(N): need the map to keep counts of each char in the string.

### Useful Links

N/A

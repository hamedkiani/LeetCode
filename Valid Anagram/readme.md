# LeetCode 242. Valid Anagram

### Link: https://leetcode.com/problems/valid-anagram/

### Difficulty: Easy

## Description

Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"

Output: true

Example 2:

Input: s = "rat", t = "car"

Output: false

Note:
You may assume the string contains only lowercase alphabets.

Follow up:

What if the inputs contain unicode characters? How would you adapt your solution to such case?

## Code and Explanation

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
      // if both strings are empty  return true
        if (s.size() == 0 && t.size() ==0)
            return true;
        // if length of strings are not similar return false
        if (s.length() != t.length())
            return false;
        // use the hash table to count each char occurrences
        unordered_map<char, int> count;
        // for each in one string add the hashtable and for another one \
         subtract the hash table. We are sure that the length of both strings \
          are same

        for(int i = 0; i < s.length(); i++){
            count[s[i]]++;
            count[t[i]]--;
        }
        // check if any char in the hashtable has non-zero occurrence
        for(auto c = count.begin(); c!=count.end(); c++)
            if (c->second != 0)
                return false;
        return true;
    }
};

```

### Time Complexity
O(N), N is the length of the string

### Space Complexity
O(N) for the hashtable
We can use sort with O(N log N) time complexity and O(1) space, with in place sort

### Useful Links

[![](http://img.youtube.com/vi/oHwDqfz1LGw/0.jpg)](http://www.youtube.com/watch?v=oHwDqfz1LGw "")

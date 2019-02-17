# LeetCode 179. Largest Number

### Link: https://leetcode.com/problems/largest-number/

### Difficulty: Medium

## Description

Given a list of non negative integers, arrange them such that they form the largest number.

Example 1:

Input: [10,2]

Output: "210"

Example 2:

Input: [3,30,34,5,9]

Output: "9534330"

Note: The result may be very large, so you need to return a string instead of an integer.

## Code and Explanation

```cpp
class Solution {
public:
    string largestNumber(vector<int>& nums) {
      // we need to sort the list in the way that given two numbers a, b, "a" + "b" > "b" + "a"
        if (nums.size() == 0)
          return "0";
        sort(nums.begin(), nums.end(), [](int a, int b){
            return to_string(a)+to_string(b) > to_string(b)+to_string(a);
        });
        string ans;
        for(int i=0; i<nums.size(); i++){
            ans += to_string(nums[i]);
        }
        return ans[0]=='0' ? "0" : ans;
    }
};
```

### Time Complexity
O(N log N) for sorting the list, like merge sort

### Space Complexity
O(1), inplace sort with no additional space, space Complexity could be O(N) is we are not allowed to modify the order of the array and/or we do not use in place sort.

### Useful Links
[![](http://img.youtube.com/vi/Cxp-qjF1Me8/0.jpg)](http://www.youtube.com/watch?v=Cxp-qjF1Me8 "")

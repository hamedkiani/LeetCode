# LeetCode 22. Generate Parentheses

### Link: https://leetcode.com/problems/generate-parentheses/

### Difficulty: Medium

## Description

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

    [
      "((()))",
      "(()())",
      "(())()",
      "()(())",
      "()()()"
    ]

## Code and Explanation

```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n)
    {
        // vector of string, each string is a possible parenthesis combination
        vector<string> res;
        helper(res, "", n , 0);
        return res;
    }

    void helper(vector<string> & res, string seq, int n, int m)
    {
      // we solve it using recursion. exit criteria is to have no open/close\
       parentheses to process. N is number of open parentheses we can use, and\
        M is the number of parentheses we need to close.       

      // if there is no more open/close parentheses to process, just add
      //  current string to the output and return.
        if (n == 0 && m == 0)
            res.push_back(seq); return;
        // if there is at least one more parentheses to process, open add,\
         reduce N by 1, and add M by 1, since for each open parenthesis we must\
          print a close parenthesis
        if (n>0)
            helper(res, seq + '(', n-1, m+1);

        // if there is at least one close parenthesis, add it to string and reduce M by 1.
        if (m> 0 )
            helper(res, seq + ")", n, m-1);
    }
};
```
### Time Complexity

The complexity of this code is O(n * Cat(n)) where Cat(n) is the nth Catalan number. There are Cat(n) possible valid strings that are valid combinations of parenthesis (see https://en.wikipedia.org/wiki/Catalan_number), and for each a string of length n is created.

### Space Complexity

O(Cat(n)): since we call the recursion for Cat(n) times, which is the number of total possible parenthesis.

### Useful Links

[![](http://img.youtube.com/vi/dzigOyGj8cw/0.jpg)](http://www.youtube.com/watch?v=dzigOyGj8cw "")

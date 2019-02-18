# LeetCode 20. Valid Parentheses

### Link: https://leetcode.com/problems/valid-parentheses/

### Difficulty: Easy

## Description

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.

Note that an empty string is also considered valid.

Example 1:

Input: "()"

Output: true

Example 2:

Input: "()[]{}"

Output: true

Example 3:

Input: "(]"

Output: false

Example 4:

Input: "([)]"

Output: false

Example 5:

Input: "{[]}"

Output: true

## Code and Explanation

```cpp
class Solution {
public:
    bool isValid(string s) {
        if (s.length()==0)
            return true;
        // the idea here is to use a stack to keep checking the visited parentheses

        // if stack is empty and we are seeing a close parentheses then return false,

        // if we see an open parentheses just push it on the stack for further check

        // if stack is not empty and we see a close parentheses, then we check \
         the top of stack, if the corresponding open parentheses is seen, then \
          pop it from stack, otherwise return false

        //  at the end check if stack is empty return true, ow return false

        stack<char> stk;

        for(auto c : s){
            if ((c == '}' || c == ')' || c == ']') && stk.empty())
                return false;
            if (c == '{' || c == '(' || c == '[')
                stk.push(c);
            if (c == '}')
                if (stk.top() != '{')
                    return false;
            else
                stk.pop();
            if (c == ']')
                if (stk.top() != '[')
                    return false;
            else
                stk.pop();

            if (c == ')')
                if (stk.top() != '(')
                    return false;
            else
                stk.pop();
        }
            return (stk.empty());
    }
};

```

### Time Complexity
O(N) for processing the string

### Space Complexity
O(N) for the stack

### Useful Links

[![](http://img.youtube.com/vi/f8Jq8Ibg2Ys/0.jpg)](http://www.youtube.com/watch?v=f8Jq8Ibg2Ys "")

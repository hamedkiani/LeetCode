# LeetCode 150. Evaluate Reverse Polish Notation

### Link: https://leetcode.com/problems/evaluate-reverse-polish-notation/

### Difficulty: Medium

## Description

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, * , /. Each operand may be an integer or another expression.

**Note:**

Division between two integers should truncate toward zero.
The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.
Example 1:

Input: ["2", "1", "+", "3", " * "]

Output: 9

Explanation: ((2 + 1) * 3) = 9

Example 2:

Input: ["4", "13", "5", "/", "+"]

Output: 6

Explanation: (4 + (13 / 5)) = 6

Example 3:

Input: ["10", "6", "9", "3", "+", "-11", "* ", "/", "* ", "17", "+", "5", "+"]

Output: 22

Explanation:

      ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
    = ((10 * (6 / (12 * -11))) + 17) + 5
    = ((10 * (6 / -132)) + 17) + 5
    = ((10 * 0) + 17) + 5
    = (0 + 17) + 5
    = 17 + 5
    = 22

## Code and Explanation

```cpp
class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        int sz = tokens.size();
        if (!sz)
            return 0;

        // using stack to keep track of the seen numbers, and output of\
         arithmetic operators is the main point of this problem.

        stack<int> stk;

        int x, y; string opt;
        int i = 0;

        // we process the input tokens from left to right.
        //  there are two options: we see either a digit, or an operator

        while(i < sz)
        {
            string temp = tokens[i];

            // if the token is a number, just push it onto the stack for further\
             processing
            if (temp != "+" && temp != "* " && temp != "/" && temp != "-")
                stk.push(stoi(temp));

            //otherwise, the token is an operator, pop two numbers from the\
             stack, apply the operator on the digits and push the result on the\
              stack for further processing

            else
            {
                x = stk.top(); stk.pop();
                y = stk.top(); stk.pop();
                stk.push(evalOpt(x,y,temp));
            }
            i++;
        }
        // at the end, the final result is the value on the top of the stack, just return it.
        return (stk.top());
    }

    int evalOpt(int x, int y, string opt)
    {
        if (opt == "+")
            x = y + x;
        else if (opt == "-")
            x = y-x;
        else if (opt == "/")
            x = y/x;
        else if (opt == "*")
            x = y*x;
        return (x);
    }
};
```

### Time Complexity

O(N): we need to process the tokens in the list

### Space Complexity

O(N): we need to use the stack to keep record of seen numbers.

### Useful Links

[![](http://img.youtube.com/vi/AVSzwzCMvyQ/0.jpg)](http://www.youtube.com/watch?v=AVSzwzCMvyQ "")

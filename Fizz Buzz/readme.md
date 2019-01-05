# LeetCode 412. Fizz Buzz

### Link: https://leetcode.com/problems/fizz-buzz/

### Difficulty: Easy

## Description

Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

Example:

n = 15,

Return:

    [
        "1",
        "2",
        "Fizz",
        "4",
        "Buzz",
        "Fizz",
        "7",
        "8",
        "Fizz",
        "Buzz",
        "11",
        "Fizz",
        "13",
        "14",
        "FizzBuzz"
    ]


## Code and Explanation

```cpp
class Solution {
public:
    vector<string> fizzBuzz(int n) {        
        vector<string> st;        
        for (int i = 1; i <= n; i++ ){
            if (i%3 == 0 && i%5 ==0)
                st.push_back("FizzBuzz");
            else if (i%3 ==0)
                st.push_back("Fizz");
            else if (i%5 ==0)
                st.push_back("Buzz");
            else
                st.push_back(to_string(i));
        }
        return st;        
    }
};
```
### Time Complexity

O(N): need a loop over the number 1,...,N

### Space Complexity

O(1) excluding the output.

### Useful Links

N/A

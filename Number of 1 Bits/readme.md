# LeetCode 191. Number of 1 Bits

### Link: https://leetcode.com/problems/number-of-1-bits/

### Difficulty: Easy

## Description

Write a function that takes an unsigned integer and return the number of '1' bits it has (also known as the Hamming weight).

Example 1:

Input: 00000000000000000000000000001011

Output: 3

Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.

Example 2:

Input: 00000000000000000000000010000000

Output: 1

Explanation: The input binary string 00000000000000000000000010000000 has a total of one '1' bit.

Example 3:

Input: 11111111111111111111111111111101

Output: 31

Explanation: The input binary string 11111111111111111111111111111101 has a total of thirty one '1' bits.

## Code and Explanation

```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n){
            count = count + (n & 1);
            // shift n one bit to right
            n = n >>1;
        }
        return count;
    }
};
```

### Time Complexity
O(N) for the loop

### Space Complexity
O(1) no additional space is used

### Useful Links
N/A

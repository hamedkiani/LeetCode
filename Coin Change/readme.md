# LeetCode 322. Coin Change

### Link: https://leetcode.com/problems/coin-change/

### Difficulty: Medium

## Description

You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11

Output: 3

Explanation: 11 = 5 + 5 + 1

Example 2:

Input: coins = [2], amount = 3

Output: -1

Note:

You may assume that you have an infinite number of each kind of coin.

## Code and Explanation

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {   
        // this is a well known problem which can be solved by dynamic\
         programming

        // we need an array to keep the minimum number of coins to exchange\
         "amount" of money

        // we need the length of array to be amount+1, because we need to\
         initialize dp[0] (when no coin is available), and the fact that in c++\
          the index is 0,...,amount-1. To keep record for amount, we need to\
           have an array of amount+1

        // since this is a "finding minimum number of coins", we initialize the\
         array by INT_MAX (we can initialize it by amount+1 as well)

        vector<int> dp(amount + 1, INT_MAX-1);
        // we initialize the dp array dp[0] by zero.

        dp[0] = 0;

        // we need to loop over amount from 1 to "amount"
        for (int i = 1; i <= amount; i++)
        {
            // we need another loop over the coins to see how each coin can can\
             contribute in finding the min number of coins

            for (int j = 0; j < coins.size(); j++)
            {
                // this is the core of this solution. For each coin, we need to\
                 see if the coin is less/equal than the amount at i. If this is\
                  the case, the coin can be used to exchange the amount,\
                   otherwise, it is not possible

                if (coins[j] <= i)
                {
                    // we need to find the minimum between dp[i], and dp[i-coins[j]] + 1. dp[i-coins[j]] + 1 means that the coin can be used in the exchange, and we add +1 to number of coins in dp[i]

                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        // at the end, we check if dp[amount] is changed or not, if it is more\
         than amount (the maximum number of coins need to exchange amount is \
          amount- using 1$ coins), there is no way to exchange amount, so \
           return -1, otherwise return dp[amount]- the minimum number of coins \
            we need to exchange "amount"
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
```

### Time Complexity

O(N*S): N is the mount, and S in number of coins

### Space Complexity

O(N): additional space for dynamic programming

### Useful Links

[![](http://img.youtube.com/vi/NJuKJ8sasGk/0.jpg)](http://www.youtube.com/watch?v=NJuKJ8sasGk "")

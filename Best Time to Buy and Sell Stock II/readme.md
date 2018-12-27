# LeetCode 122. Best Time to Buy and Sell Stock II

### Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

### Difficulty: Easy

## Description

Say you have an array for which the *ith* element is the price of a given stock on day *i*.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Example 2:

Input:

    [1,2,3,4,5]

Output: 4

Explanation:

    Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
    Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.

Example 3:

Input:

    [7,6,4,3,1]

Output: 0

Explanation:

    In this case, no transaction is done, i.e. max profit = 0.

## Code and Explanation

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // if there is just one day the profit is 0, you either not buy, or buy and sell the same stock
        if(prices.size() <= 1) return 0;
        int res = 0;
        // go over all days, and see if the stock price at day i is more than day i-1, buy at day i-1 and sell it at day i
        for( size_t i = 1; i < prices.size(); i++)
            if( prices[i] - prices[i-1] > 0 )
                res += prices[i] - prices[i-1];
        return res;
    }
};
```

### Time Complexity

O(N)

A single loop over the array is needed.

### Space Complexity

O(1)

No additional memory is required.

### Useful Links

[![](http://img.youtube.com/vi/vxIMqdR8flY/0.jpg)](http://www.youtube.com/watch?v=vxIMqdR8flY "")

# LeetCode 121. Best Time to Buy and Sell Stock

### Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

### Difficulty: Easy

## Description

Say you have an array for which the *ith* element is the price of a given stock on day *i*.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

**Note that you cannot sell a stock before you buy one.**

Example 1:

Input:

    [7,1,5,3,6,4]

Output: 5

Explanation:

    Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
                 Not 7-1 = 6, as selling price needs to be larger than buying price.
Example 2:

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
        // we need to keep track of min value and maximum profit over a loop
        int minVal = INT_MAX;
        int maxVal = 0;
        for(int i = 0; i < prices.size(); i++){
            // min value is the minimum value seen so far
            minVal = min(minVal , prices[i] );
            // max profit seen so far based on current min value
            maxVal = max(maxVal, prices[i]-minVal);
        }
        return maxVal;
    }
};
```

### Time Complexity

O(N)

A loop over the array.

### Space Complexity

O(1)

No additional space is used.

### Useful Links

[![](http://img.youtube.com/vi/kwaMvB7nhJw/0.jpg)](http://www.youtube.com/watch?v=kwaMvB7nhJw "")


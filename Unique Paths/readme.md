# LeetCode 62. Unique Paths

### Link: https://leetcode.com/problems/unique-paths/

### Difficulty: Medium

## Description

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 7 x 3 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

Example 1:

Input: m = 3, n = 2

Output: 3

Explanation:

From the top-left corner, there are a total of 3 ways to reach the bottom-right
corner:
```
  1. Right -> Right -> Down
  2. Right -> Down -> Right
  3. Down -> Right -> Right
```
Example 2:

Input: m = 7, n = 3

Output: 28

## Code and Explanation

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
      // if its a 1D vector just return 1
        if (m == 1 || n == 1 )
            return 1;
      // if it is an empty vector just return 0
        if (m == 0 && n ==0 )
            return m;
        // now, let's do some dynamic programming with a 2D vector of size mxn
        vector<vector<int>> DP(m, vector<int>(n,1));
        // over each row and each column:
        // the number of paths from [0][0] to dp[i][j] is equal to the \
         summation of number of path from [0][0] to dp[i-1][j] and number of \
          path from [0][0] to dp[i][j-1]- to right or down

        for(int i = 1 ; i < m; i++)
            for (int j = 1; j < n; j++)
                DP[i][j] = DP[i-1][j] + DP[i][j-1];
        return DP[m-1][n-1];

        // we can do it using a 1D vector. In 2D vector solution, each row is the summation of elements in the previous row.         

        // if (m < n)
        //     return uniquePaths(n, m);
        // we initialize the 1D vector with 1s
        // vector<int> cur(m, 1);
        // for(int i = 1; i < n; i++)
        //     for(int j = 1; j < m; j++)
        //         cur[j] = cur[j-1] + cur[j];
        // return cur.back();
    }
};

```

### Time Complexity
O(NxM) because of the nested loops

### Space Complexity
O(MxN) for the first solution and O(M) for the second solution, assuming M>N

### Useful Links

[![](http://img.youtube.com/vi/GO5QHC_BmvM/0.jpg)](http://www.youtube.com/watch?v=GO5QHC_BmvM "")

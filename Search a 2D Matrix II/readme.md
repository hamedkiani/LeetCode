# LeetCode 240. Search a 2D Matrix II

### Link: https://leetcode.com/problems/search-a-2d-matrix-ii/

### Difficulty: Medium

## Description

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
Example:

Consider the following matrix:
```
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
```

Given target = 5, return true.

Given target = 20, return false.

## Code and Explanation

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if (row == 0 )
            return false;
        int col = matrix[0].size();
        // because of having sorted rows and columns, the approach for this problem is based on divide and conquer

         //  we use to indicator, one for rows, another one for columns
         // these indicators narrow down the search area

        int r = 0;
        int c = col-1;

        while(r < row && c >= 0){
            if (matrix[r][c] == target)
            // target is found
                return true;
            if (target > matrix[r][c])
            // if target > matrix[r][c] then we need to go to next row
                r++;
            else
            // if target < matrix[r][c] then we need to go to previous column
                c--;
        } // while
        return false;
    }
};

```

### Time Complexity
O(N+M) for a matrix of MxN

### Space Complexity
O(1)

### Useful Links

[![](http://img.youtube.com/vi/ZhG1M_FzxgI/0.jpg)](http://www.youtube.com/watch?v=ZhG1M_FzxgI "")

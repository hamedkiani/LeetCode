# LeetCode 73. Set matrix zero

### Link: https://leetcode.com/problems/set-matrix-zeroes/

### Difficulty: Medium

## Description

Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input:
```
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
```
Output:
```
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
```
Example 2:

Input:
```
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
```
Output:
```
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
```

## Code and Explanation

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if (!row)
            return;
        int col = matrix[0].size();

        vector<int> rows;
        vector<int> cols;
        // find the index of zero elements
        for(int r = 0; r < row; r++){
            for (int c = 0; c < col; c++){
                if (!matrix[r][c]){
                    rows.push_back(r);
                    cols.push_back(c);
                }//if
            }// for c
        } // for r
        // go over the rows/cols and set to zero cross-shape on the zeros
        for (int i = 0; i < rows.size(); i++){
            for(int r = 0; r < row; r++)
                matrix[r][cols[i]] = 0;

            for(int c = 0; c < col; c++)
                matrix[rows[i]][c] = 0;
        }
        return;
    }
};

```
### Time Complexity
O(NxM) for a matrix of size of NxM

### Space Complexity
O(n + m)

### Useful Links
N/A

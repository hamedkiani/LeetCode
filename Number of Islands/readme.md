# LeetCode 200. Number of Islands

### Link: https://leetcode.com/problems/number-of-islands/

### Difficulty: Medium

## Description

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
```
  11110
  11010
  11000
  00000
```

Output: 1

Example 2:

Input:
```
  11000
  11000
  00100
  00011
```

Output: 3

## Code and Explanation

```cpp
// this is my favorite problem on leetcode !!!!
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if (!row)
            return 0;
        int col = grid[0].size();
        int num_islands = 0;
        // we check every element to see if it is 1 or not.
        // if 1: an island is seen. recursively set to zero its 4-way neighbor elements to avoid redundant counting
        // if 0: do nothing
        for(int r = 0; r < row; r++){
            for(int c = 0; c < col; c++){
                if (grid[r][c] == '1'){
                    num_islands++;
                    dfs(grid, r, c);
                }//if
            }//for
        }//for
        return num_islands;
    }

    void dfs(vector< vector<char>> &grid, int r, int c){
      // we set the value of [r,c] to zero to avoid double counting
        grid[r][c] = '0';
        int nr = grid.size();
        int nc = grid[0].size();

        // check the 4-way neighbor of [r,c], if any is "1", recursively \
         process it (set to zero)- and go on
        // must check the boundary of the array- to avoid out of memory

        if(r-1 >= 0 && grid[r-1][c] == '1' )
              dfs(grid, r-1, c);
        if(c-1 >= 0 && grid[r][c-1] == '1' )
              dfs(grid, r, c-1);
        if(r+1 < nr && grid[r+1][c] == '1' )
              dfs(grid, r+1, c);
        if(c+1 <nc && grid[r][c+1] == '1' )
              dfs(grid, r, c+1);
    }
};

```

### Time Complexity
O(N^2) for the 2D array of size N*N

### Space Complexity
O(N) for the recursion stack

### Useful Links
N/A

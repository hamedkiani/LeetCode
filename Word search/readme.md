# LeetCode 79. Word search

### Link: https://leetcode.com/problems/word-search/

### Difficulty: Medium

## Description

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
```
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
```

Given word = "ABCCED", return true.

Given word = "SEE", return true.

Given word = "ABCB", return false.

## Code and Explanation

```cpp
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // empty string
        if (word.length() == 0)
            return false;
        int row = board.size();
        if (!row)
            return false;
        int col = board[0].size();
        if (row*col < word.length())
            return false;
        if (row*col == word.length() && word.length() == 1)
            return word[0] == board[0][0];

        // we check every element in the 2D board to see if we can see the \
         first char of the word, if so we call the recursive function to check \
          the rest of the word in the board. If we could find all chars in the \
           board then return true, ow return false.

        for(int r = 0; r < row; r++){
            for (int c = 0; c < col; c++){
                if (helper(board, word, 0, r, c))
                    return true;
            }
        }
        return false;
    }

    bool helper(vector<vector<char>> & board, string word, int beg, int r, int c){
      // if we successfully checked all chars, then we done and return true
        if (beg >= word.length()) return true;

        // check if the char at board[r][c] are same as the char at word[beg]
        if (board[r][c] == word[beg]){
          // we buffer the char at board[r][c] and replace it with a strange char like "*" to avoid unlimited search
            char temp = board[r][c];
            board[r][c] = '*';
            // we check the 4-connection of [r][c] for next char in the word
            if (r-1 >= 0 &&  helper(board, word, beg+1, r-1, c))
                return true;
            if (c-1 >= 0 && helper(board, word, beg+1, r, c-1))
                return true;
            if (r+1 < board.size() && helper(board, word, beg+1, r+1, c))
                return true;
            if (c+1 < board[0].size() && helper(board, word, beg+1, r, c+1))
                return true;
            // we undo the change in the board with the buffered char
            board[r][c] = temp;
        }
        return false;
    }
};

```

### Time Complexity
O(NxMx4) we may need to explore 4-connections of each char in the entire board

### Space Complexity
O(NxM) for the recursion stack

### Useful Links
N/A

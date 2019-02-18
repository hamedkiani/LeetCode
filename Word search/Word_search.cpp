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
        for(int r = 0; r < row; r++){
            for (int c = 0; c < col; c++){
                if (helper(board, word, 0, r, c))
                    return true;
            }
        }
        return false;
    }

    bool helper(vector<vector<char>> & board, string word, int beg, int r, int c){
        if (beg >= word.length()) return true;

        if (board[r][c] == word[beg]){
            char temp = board[r][c];
            board[r][c] = '*';
            if (r-1 >= 0 &&  helper(board, word, beg+1, r-1, c))
                return true;
            if (c-1 >= 0 && helper(board, word, beg+1, r, c-1))
                return true;
            if (r+1 < board.size() && helper(board, word, beg+1, r+1, c))
                return true;
            if (c+1 < board[0].size() && helper(board, word, beg+1, r, c+1))
                return true;
            board[r][c] = temp;
        }
        return false;
    }
};

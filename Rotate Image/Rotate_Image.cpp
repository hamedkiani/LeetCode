class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (!matrix.size())
            return;

        int row = matrix.size();
        int col = matrix[0].size();

        // transpose - inplace, O (nxn)
        for (int r = 0; r < row; r++)
            for (int c = 0; c < r; c++)
                    swap(matrix[r][c], matrix[c][r]);
        // exchange/reverse cols
        for(int i = 0; i < row; i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};

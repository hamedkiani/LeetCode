class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if (!row)
            return;
        int col = matrix[0].size();

        vector<int> rows;
        vector<int> cols;

        for(int r = 0; r < row; r++){
            for (int c = 0; c < col; c++){
                if (!matrix[r][c]){
                    rows.push_back(r);
                    cols.push_back(c);
                }//if
            }// for c
        } // for r

        for (int i = 0; i < rows.size(); i++){
            for(int r = 0; r < row; r++)
                matrix[r][cols[i]] = 0;

            for(int c = 0; c < col; c++)
                matrix[rows[i]][c] = 0;
        }
        return;
    }
};

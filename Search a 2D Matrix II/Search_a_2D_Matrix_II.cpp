class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if (row == 0 )
            return false;
        int col = matrix[0].size();

        int r = 0;
        int c = col-1;

        while(r < row && c >= 0){
            if (matrix[r][c] == target)
                return true;
            if (target > matrix[r][c])
                r++;
            else
                c--;
        } // while
        return false;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if (!row)
            return 0;
        int col = grid[0].size();
        int num_islands = 0;
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
        grid[r][c] = '0';
        int nr = grid.size();
        int nc = grid[0].size();
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

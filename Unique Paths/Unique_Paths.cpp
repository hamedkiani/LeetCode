class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1 )
            return 1;
        if (m == 0 && n ==0 )
            return m;
        vector<vector<int>> DP(m, vector<int>(n,1));
        for(int i = 1 ; i < m; i++)
            for (int j = 1; j < n; j++)
                DP[i][j] = DP[i-1][j] + DP[i][j-1];
        return DP[m-1][n-1];
        // the following is using a 1D vector 
//         if (m < n)
//             return uniquePaths(n, m);
//         vector<int> cur(m, 1);
//         for(int i = 1; i < n; i++)
//             for(int j = 1; j < m; j++)
//                 cur[j] = cur[j-1] + cur[j];
//         return cur.back();
    }
};

class Solution {
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        helper(res, "", n , 0);
        return res;
    }

    void helper(vector<string> & res, string seq, int n, int m)
    {
        if (n == 0 && m == 0)
            res.push_back(seq); return;
        if (n>0)
            helper(res, seq + '(', n-1, m+1);
        if (m> 0 )
            helper(res, seq + ")", n, m-1);
    }
};

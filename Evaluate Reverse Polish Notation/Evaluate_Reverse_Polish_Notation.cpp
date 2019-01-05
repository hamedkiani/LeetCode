class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        int sz = tokens.size();
        if (!sz)
            return 0;
        stack<int> stk;
        int x, y; string opt;
        int i = 0;
        while(i < sz){
            string temp = tokens[i];
            if (temp != "+" && temp != "*" && temp != "/" && temp != "-")
                stk.push(stoi(temp));
            else
            {
                x = stk.top(); stk.pop();
                y = stk.top(); stk.pop();
                stk.push(evalOpt(x,y,temp));
            }
            i++;
        }
        return (stk.top());
    }

    int evalOpt(int x, int y, string opt)
    {
        if (opt == "+")
            x = y + x;
        else if (opt == "-")
            x = y-x;
        else if (opt == "/")
            x = y/x;
        else if (opt == "*")
            x = y*x;
        return (x);
    }
};

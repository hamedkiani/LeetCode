class Solution {
public:
    bool isValid(string s) {
        if (s.length()==0)
            return true;
        stack<char> stk;
        for(auto c : s){
            if ((c == '}' || c == ')' || c == ']') && stk.empty())
                return false;
            if (c == '{' || c == '(' || c == '[')
                stk.push(c);
            if (c == '}')
                if (stk.top() != '{')
                    return false;
            else
                stk.pop();
            if (c == ']')
                if (stk.top() != '[')
                    return false;
            else
                stk.pop();

            if (c == ')')
                if (stk.top() != '(')
                    return false;
            else
                stk.pop();
        }
            return (stk.empty());
    }
};
